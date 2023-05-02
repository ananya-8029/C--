#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter number of nodes:";
    cin>>n;
    int m;
    cout<<"Enter number of edges:";
    cin>>m;

    vector<vector<int>>edges(m);

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        edges[i].push_back(u);
        edges[i].push_back(v);
    }
    
    //assuming graph as undirected
    vector<vector<int>>ans(n);
    //ans array will store all the adjacent nodes corresponding to the index
    for(int i=0;i<m;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        ans[u].push_back(v);
        ans[v].push_back(u);
    }
    cout<<"Ans vector:"<<endl;
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    //creating adjacency list
    vector<vector<int>>adj(n);

    for(int i=0;i<n;i++){
        adj[i].push_back(i);
        //entering neighbours
        for(int j=0;j<ans[i].size();j++){
            adj[i].push_back(ans[i][j]);
        }
    }
    cout<<"Adjacency List"<<endl;
    for(auto i:adj){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}