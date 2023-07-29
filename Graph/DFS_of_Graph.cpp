#include <bits/stdc++.h>
using namespace std;

class graph
{
public:
    // creating an adjacency list
    unordered_map<int, list<int>> adj;
    void addEdge(int u, int v, int direction)
    {
        adj[u].push_back(v);
        // checking if the graph is undirected where 0 indicates that the graph is undirected while 1 indicates that the graph is directed
        if (!direction)
        {
            adj[v].push_back(u);
        }
    }

    void DFS(int node, unordered_map<int, bool> &visited, vector<int> &ans)
    {
        ans.push_back(node);
        visited[node] = 1;

        for (auto i : adj[node])
        {
            if (!visited[i])
            {
                DFS(i, visited, ans);
            }
        }
    }

    void printAdjList()
    {
        for (auto i : adj)
        {
            cout << i.first << "->";
            for (auto j : i.second)
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int n;
    cout << "Enter no. of nodes:";
    cin >> n;
    int e;
    cout << "Enter no. of edges:";
    cin >> e;

    graph g;
    // looping for inserting edges
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        // creating an edge
        // here 0 specifies that the graph need to be undirected
        g.addEdge(u, v, 0);
    }
    cout << "Adjacency List:" << endl;
    g.printAdjList();
    unordered_map<int, bool> visited;
    vector<int> ans;
    // considering that the graph is disconnected also we can have vectors of vector to store the dfs traversal of each component
    // for (int i = 0; i < n; i++)
    // {
        // vector<int>components;
    //     if (!visited[i])
    //     {
    //         g.DFS(i, visited, components);
    //     }
    // ans.push_back(components)
    //where ans is -> vector<vector<int>>ans
    // }

    //when the graph is connected
    g.DFS(2, visited, ans);

    cout<< "DFS traversal:"<<endl;
    for(auto i:ans){
        cout<<i<<" ";
    }

    return 0;
}