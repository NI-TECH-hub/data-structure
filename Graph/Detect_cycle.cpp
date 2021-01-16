#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Graph {
    public:
    int V;
    list<int>*adj;

    Graph(int n) {
        this->V=n;
        this->adj=new list<int>[n];
    }
    void addedge(int u,int v) {
        adj[u].push_back(v);
    }

    bool iscyclic(int src,unordered_map<int,bool>&visited,unordered_map<int,bool>&marked) {
        // if i have already visited the vertex then no need to visit it again 
        if(not visited[src]) {
            // mark the vertex visited 
            visited[src]=true;
            // push it to stack or mark as a stack 
            marked[src]=true;
            // go to its neighbours 
            for(auto neighbour :this->adj[src]) {
                // make a recursive call whether i have visted that node again or not if not then return false and goto next statement 
                if(not visited[neighbour]  && iscyclic(neighbour,visited,marked)){
                    return true;
                }
                // check whethe the node which i have visited is in the stack if yes then it have been come from someone else so it 
                // contains a cycle simpy return true 
                else if(marked[neighbour]) {
                    return true;
                }
            }
        }
        //since i am not visiting that vertex make if false 
        marked[src]=false;
        // return false 
        return false;
    }
    bool Detect_path() {
        unordered_map<int,bool>visited;
        unordered_map<int,bool>marked;
        for(int i=0;i<this->V;i++) {
            // travel for each node 
            if(iscyclic(i,visited,marked)) {
                // if the ans is yes then retun 
                return true;
            }
        }
        return false;
    }

};

int main() {
    Graph g(4);
    g.addedge(0,1);
    g.addedge(0,2);
    g.addedge(2,0);
    g.addedge(1,2);
    g.addedge(2,3);
    g.addedge(3,3);
    cout<<g.Detect_path();
    //  removing edges between 2,0 && 3,3 will make it not detect cycle so the ans will be one 
    return 0;
}