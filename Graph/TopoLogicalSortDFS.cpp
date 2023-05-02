#include<bits/stdc++.h>
using namespace std;

class graph {
    public:
    unordered_map<int,list<int>>adj;
    void addEdge(int u,int v){
        adj[u].push_back(v);
    }

    void topologicalSortDfs(int node, unordered_map<int,bool>&visited, stack<int>&s){
        visited[node]=1;

        for(auto i:adj[node]){
            if(!visited[i]){
                topologicalSortDfs(i,visited,s);
            }
        }
        s.push(node);
    }
};

int main(){
    int n;
    cout<<"Enter no. of nodes:";
    cin>>n;

    int e;
    cout<<"Enter no. of edges:";
    cin>>e;

    graph g;

    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v);
    }
    unordered_map<int,bool>visited;
    stack<int>s;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            g.topologicalSortDfs(i,visited,s);
        }
    }
    cout<<"Topological Sort of the given graph:"<<endl;
    while(!s.empty()){
        int top=s.top();
        cout<<top<<" ";
        s.pop();
    }
    return 0;
}