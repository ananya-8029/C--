#include <bits/stdc++.h>
using namespace std;

class graph
{
public:
    unordered_map<int, list<int>> adj;
    void addEdge(int u, int v, bool direction)
    {
        // direction=0 -> undirected
        // direction=1 -> directed

        // create an edge from u to v
        adj[u].push_back(v);
        if (direction == 0)
        {
            // if it is true it means that the graph is undirected and this we allow both ways
            adj[v].push_back(u);
        }
    }

    void BFS(int node, int n, unordered_map<int, bool> &visited, vector<int> &ans)
    {
        queue<int> q;
        // supposing that bfs starts from vertex 0
        q.push(node);
        visited[node] = true;

        while (!q.empty())
        {
            int frontNode = q.front();
            q.pop();

            ans.push_back(frontNode);

            for (auto i : adj[frontNode])
            {
                if (!visited[frontNode])
                {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }

    void printAdjList()
    {
        for (auto i : adj)
        {
            cout << i.first << "-> ";
            for (auto j : i.second)
            {
                cout << j << ", ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int n;
    cout << "Enter the number of nodes:";
    cin >> n;
    int e;
    cout << "Enter the number of edges:";
    cin >> e;

    graph g;

    for (int i = 0; i < e; i++)
    {
        int u, v; // u and v are vertex 1 to vertex 2
        cin >> u >> v;
        // creating an edge
        g.addEdge(u, v, 0);
    }

    cout << "Adjacency list:" << endl;
    g.printAdjList();
    unordered_map<int, bool> visited;
    vector<int> ans;
    // if we have disconnected graph we use loop to visit all vertices
    //  for (int i = 0; i < n; i++)
    //  {
    //      if (!visited[i])
    //      {
    //          g.BFS(i,n, visited, ans);
    //      }
    //  }

    //if the graph is connected then we need no to use loop since all nodes are connected
    g.BFS(0, n, visited, ans);
    cout << "BFS travesal of the given graph is:" << endl;
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}