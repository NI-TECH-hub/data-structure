#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Graph{
    public:
    int V;
    list<int>*adj;
    Graph(int n){
        this->V=n;
        this->adj=new list<int>[n];
    }
    void addedge(int u,int v,bool bidir=true){
        adj[u].push_back(v);
        if(bidir){
            adj[v].push_back(u);
        }
    }
    void BFShelper(int src,unordered_map<int,bool>&visited) {
        visited[src]=true;
        cout<<src<<" ";
        queue<int>q;
        q.push(src);
        for(auto i:adj[src]){
            if(not visited[i]){
                BFShelper(i,visited);
            }
        }
    }
    void BFS(int src){
        unordered_map<int,bool>visited;
        BFShelper(src,visited);
    }

};

int main(){
    Graph g(6);
    g.addedge(2,1);
    g.addedge(4,2);
    g.addedge(3,2);
    g.addedge(4,3);
    g.addedge(5,3);
    g.addedge(4,5);
    g.BFS(2);
}