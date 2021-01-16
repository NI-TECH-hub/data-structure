#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
    // function to add edge to list
    void addedge(list<int>*adj,int u,int v) {
        adj[u].push_back(v);
    }

    // function to display the particular list 
    void display(list<int>*adj,int V) {
        for(int i=0;i<V;i++) 
        {
            cout<<i<<"-->";
            for(auto neighbour:adj[i]) {
                cout<<neighbour<<",";
            }
            cout<<endl;
        }
    }

    // function to tranpose the list 
    void transpose(list<int>*tp,int V,list<int>*adj){
        for(int i=0;i<V;i++)
        {
            // visited all neighbour of i and and add the edge from there to i 
            for(auto neighbour:adj[i]) {
                addedge(tp,neighbour,i);
            }
        }
    }
};

int main() 
{
    // creating a adjancency list 
    list<int>*adj=new list<int>[5];
    Graph g;
    g.addedge(adj,0,4);
    g.addedge(adj,0,3);
    g.addedge(adj,2,0);
    g.addedge(adj,0,1);
    g.addedge(adj,3,2);
    g.addedge(adj,4,1);
    g.addedge(adj,4,3);
    g.display(adj,5);

    // list to store the transpose of the graph 
    list<int>*tranpose=new list<int>[5];
    g.transpose(tranpose,5,adj);
    cout<<endl<<"Tranpose matrix is "<<endl;
    g.display(tranpose,5);
    return 0;
     
}