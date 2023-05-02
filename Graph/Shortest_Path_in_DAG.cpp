#include <bits/stdc++.h>
using namespace std;
// finding the shortest path of a Directed Acyclic Graph using the stack...
class graph
{
public:
    void printAdj(unordered_map<int, list<pair<int, int>>> adj)
    {
        for (auto i : adj)
        {
            cout << i.first << "->";
            for (auto j : i.second)
            {
                cout << " (" << j.first << "," << j.second << ") ";
            }
            cout << endl;
        }
    }

    void topologicalSort(int node, unordered_map<int, bool> &visited, stack<int> &s, unordered_map<int, list<pair<int, int>>> adj)
    {
        visited[node] = 1;

        for (auto i : adj[node])
        {
            if (!visited[i.first])
            {
                topologicalSort(i.first, visited, s, adj);
            }
        }
        s.push(node);
    }
};

int main()
{
    int n;
    cout << "Enter the no. of nodes: ";
    cin >> n;
    int e;
    cout << "Enter the no. of edges ";
    cin >> e;

    graph g;

    // Adjacency list of weighted graph ie edges having weights
    unordered_map<int, list<pair<int, int>>> adj;
    cout << "Enter nodes and their edges's weight:" << endl;
    for (int i = 0; i < e; i++)
    {
        int u, v, weight;
        cin >> u >> v >> weight;

        adj[u].push_back(make_pair(v, weight));
    }

    cout << "Adjacency list if as follows:" << endl;
    g.printAdj(adj);

    unordered_map<int, bool> visited;
    stack<int> s; // storing the topological sort

    // for finding topological sort
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            g.topologicalSort(i, visited, s, adj);
    }

    vector<int>dist(n);

    //all the distance as infinity
    for(int i=0;i<n;i++){
        dist[i]=INT_MAX;
    }
    int src;
    cout<<"Enter the source to find the shortest path from that node to all other vertices: ";
    cin>>src;

    dist[src]=0;

    //now finding the shortest path
    while(!s.empty()){
        int top=s.top();
        s.pop();

        for(auto i:adj[top]){
            if(dist[top]!=INT_MAX){
                if((dist[top]+i.second) < dist[i.first]){
                    dist[i.first]=dist[top]+i.second;
                }
            }
        }
    }

    cout<<"The Shortest Path from "<<src<<"to all other nodes is:"<<endl;

    for(auto i:dist){
        cout<<i<<" ";
    }

    return 0;
}