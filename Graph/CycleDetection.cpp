#include <bits/stdc++.h>
using namespace std;

class graph
{
public:
    unordered_map<int, list<int>> adj;
    void addEdge(int u, int v, int direction)
    {
        adj[u].push_back(v);
        if (!direction)
        {
            adj[v].push_back(u);
        }
    }

    // cycle detection in an undirected graph using bfs
    bool CycleBfs(int node, unordered_map<int, bool> &visited)
    {
        unordered_map<int, int> parent;
        queue<int> q;
        q.push(node);
        visited[node] = 1;
        parent[node] = -1;

        while (!q.empty())
        {
            int frontNode = q.front();
            q.pop();

            for (auto i : adj[frontNode])
            {
                if (!visited[i])
                {
                    q.push(i);
                    visited[i] = 1;
                    parent[i] = frontNode; // this keeps track that each frontNode is the parent of the next adjacent node
                }
                else if (parent[frontNode] != i) // this condition states that the front of the queue is visited and checks that if it has the same parent or not
                {
                    return true;
                }
            }
        }
        return false;
    }

    // cycle detection of undirected graph using dfs
    bool CycleDfs(int node, int parent, unordered_map<int, bool> &visited)
    {
        visited[node] = 1;
        for (auto i : adj[node])
        {
            if (!visited[i])
            {
                bool cycleDetected = CycleDfs(i, node, visited);
                if (cycleDetected)
                {
                    return true;
                }
            }
            else if (parent != i)
            {
                return true;
            }
        }
        return false;
    }

    // Cycle Detection of directed graph using dfs
    // the difference is only that we need to track all the node that are in the stack of recursion...if the node is visited and it is already present in the stack then we can say that the cycle is present

    bool checkCycleDfs(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited)
    {
        // unordered_map<bool,int>dfsVisited....to maintain the track for the nodes that are in the stack and if the are popped out or we can say return to previous node then we assign the dfsVisited of that node as false;
        visited[node] = 1;
        dfsVisited[node] = 1;

        for (auto i : adj[node])
        {
            if (!visited[node])
            {
                bool cycleCheck = checkCycleDfs(i, visited, dfsVisited);
                if (cycleCheck)
                {
                    return true;
                }
            }
            else if (dfsVisited[node])
            {
                return true;
            }
        }
        dfsVisited[node] = 0; // this statement means that when one function call is completed and transferred to the previous node then we have to mark the present node as false
        return false;
    }

    // cycle detection in directed graph using bfs
    // we can use topolotgical sort using bfs (Kahn's Algorithm) to detect if the graph contains a cycle a graph
    bool checkCycleBfs(int v)
    {
        // creating indegree
        vector<int> indegree(v);
        for (auto i : adj)
        {
            for (auto j : i.second)
            {
                indegree[j]++;
            }
        }

        // creating queue
        queue<int> q;

        // pushing the node which has indegree 0 in queue
        for (int i = 0; i < v; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        // now we can do bfs
        // inorder to see if topological sort is valid or not we can create a count variable which we increment when we pop an element from the queue and if the count == nodes.present this means that the topological is vaid and no cycle is present
        int count = 0;
        while (!q.empty())
        {
            int frontNode = q.front();
            q.pop();

            count++;
            for (auto i : adj[frontNode])
            {
                indegree[i]--;
                if (indegree[i] == 0)
                {
                    q.push(i);
                }
            }
        }
        if (count == v)
        {
            return false;
        }
        else
        {
            return true;
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
        g.addEdge(u, v, 1);
    }
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;
    bool isCycle;
    // for disconnected graph or mostly recommended
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            isCycle = g.checkCycleDfs(i, visited, dfsVisited);
        }
    }
    // for connected graph
    // bool isCycle = g.checkCycleDfs(0, visited, dfsVisited);
    if (isCycle)
        cout << "There is a cycle";
    else
        cout << "There is no cycle";
    return 0;
}