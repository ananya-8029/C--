#include<bits/stdc++.h>
using namespace std;
//Adjacency list representation of a graph
class graph {
    public:
        //int -> vertex   list -> edge connecting
        unordered_map<int, list<int>> adj;
        void addEdge(int u, int v, bool direction){
            //direction=0 -> undirected
            //direction=1 -> directed

            //create an edge from u to v
            adj[u].push_back(v);
            if(direction == 0){
                //if it is true it means that the graph is undirected and this we allow both ways
                adj[v].push_back(u);
            }
        }

        void printAdjList(){
            for(auto i:adj){
                cout<< i.first << "-> ";
                for(auto j: i.second) {
                    cout<<j<<", ";
                }
                cout<<endl;
            }
        }
};

int main(){
    int n;
    cout<<"Enter the number of nodes:";
    cin>>n;
    int e;
    cout<<"Enter the number of edges:";
    cin>>e;

    graph g;

    for(int i=0;i<e;i++){
        int u,v;//u and v are vertex 1 to vertex 2
        cin>>u>>v;
        //creating an edge
        g.addEdge(u,v,0);
    }

    //printing graph4
    g.printAdjList();

    return 0;
}