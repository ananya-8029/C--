#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the no. of nodes:";
    cin >> n;

    int e;
    cout << "Enter the no. of edges:";
    cin >> e;
    cout << "Enter the nodes and their edge's wwight:" << endl;

    // Adjacency list
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < e; i++)
    {
        int u, v, weight;
        cin >> u >> v >> weight;
        // graph is undirected
        adj[u].push_back(make_pair(v, weight));
        adj[v].push_back(make_pair(u, weight));
    }

    cout << "Enter the source node to find the smallest distance:";
    int src;
    cin >> src;
    // Creation of Distance vector with infinite value initially
    vector<int> dist(n);
    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;

    // creation of set on basis of (distance of node, node)
    set<pair<int, int>> st;
    // set will help us to keep track of the minimum weight of edge among all the neighbours of a node
    st.insert(make_pair(0, src));

    // now creating the logic to find the algorithm
    while (!st.empty())
    {
        // fetch the top record
        auto top = *(st.begin());

        // extract the data of the given top
        int distanceNode = top.first;
        int node = top.second;
        // removing the top
        st.erase(st.begin());

        // now traversing the node's neighbours
        for (auto i : adj[node])
        {

            // checking if the i , which contains the adjacent vertex and the weight of the edge, if i's vertex distance in the distance vector is greater than the sum of the distance node and i's edge
            if ((distanceNode + i.second) < dist[i.first])
            {

                auto record = st.find(make_pair(dist[i.first], i.first));

                // if record found then erase that
                if (record != st.end())
                {
                    st.erase(record); // we need to remove the node if we found smaller distance of the same node than the distance present in the pair in the set
                }

                // distance update
                dist[i.first] = distanceNode + i.second;

                // insert in the set
                st.insert(make_pair(dist[i.first], i.first));
            }
        }
    }
    cout << "The shortest path is as follows:" << endl;
    for (auto i : dist)
    {
        cout << i << " ";
    }
    return 0;
}