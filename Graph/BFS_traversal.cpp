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
    void helper(int src,unordered_map<int,bool> &visited) {
        visited[src]=true;
        queue<int>qq;
        qq.push(src);
        while(not qq.empty()) {
            int value=qq.front();
            qq.pop();
            for(auto neighbour : this->adj[value]) {
                if(not visited[neighbour]) {
                    visited[neighbour] =true;
                    qq.push(neighbour);
                }
            }
            cout<<value<<" ";
        }
        cout<<endl;
    }

    void BFS(int src) {
        unordered_map<int,bool>visited;
        helper(src,visited);
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