#include <bits/stdc++.h>
using namespace std;
//we can term it as Kahn's Algorithm...
int main()
{
    int n;
    cout << "Enter no. of nodes: ";
    cin >> n;

    int e;
    cout << "Enter no. of edges: ";
    cin >> e;

    //Step I:Creating adjacent list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    // step II:Creating indegree of every vertex
    vector<int> indegree(n);
    for(auto i:adj){
        for(auto j:i.second){
            indegree[j]++;
        }
    }

    //make a queue
    queue<int>q;
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    cout<<"Indegree:"<<endl;
    for(auto i:indegree){
        cout<<i<<" ";
    }
    cout<<endl<<"Adjacent List:"<<endl;
    for (auto i:adj){
        cout<<i.first<<"->";
        for(auto j:i.second){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    //for storing the order
    vector<int>ans;
    //making topological sort using Bfs
    while(!q.empty()){
        int frontNode=q.front();
        q.pop();
        ans.push_back(frontNode);

        for(auto i:adj[frontNode]){
            indegree[i]--;
            if(indegree[i]==0){
                q.push(i);
            }
        }
    }
    cout<<"Topological Sort of the given graph:"<<endl;
    for(auto i:ans){
        cout<<i<<" ";
    }

    return 0;
}