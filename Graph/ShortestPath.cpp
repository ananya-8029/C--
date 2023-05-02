#include <bits/stdc++.h>
using namespace std;
// finding shortest path in an undirected graph using BFS
int main()
{
    int n;
    cout << "Enter no. of nodes: ";
    cin >> n;

    int e;
    cout << "Enter no. of edges: ";
    cin >> e;

    // adjacency list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int src, dest;
    cout << "Enter source node: ";
    cin >> src;

    cout << "Enter destination node: ";
    cin >> dest;

    // creating a visited vector to track of the nodes that are visited
    unordered_map<int, bool> visited;
    // creating a parent vector to track the node's parent
    unordered_map<int, int> parent;
    // queue for ordering
    queue<int> q;
    q.push(src);
    visited[src] = 1;
    parent[src] = -1;

    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        for (auto i : adj[frontNode])
        {
            if (!visited[i])
            {
                visited[i] = 1;
                parent[i] = frontNode;
                q.push(i);
            }
        }
    }

    // using parent to find out the shortest path....the idea is to backtrack from the destination node to the src node....this will provide the shorted path
    vector<int> ans;
    int currentNode = dest;
    ans.push_back(currentNode);
    while (currentNode != src)
    {
        currentNode = parent[currentNode];
        ans.push_back(currentNode);
    }
    reverse(ans.begin(),ans.end());
    for (auto i : ans)
    {
        cout << i << "->";
    }


    return 0;
}