#include<iosteam>
#include<bits/stdc++.h>
using namespace std;

class graph{
    int v;
    vector<int> adj[];
    // Function to detect cycle in a directed graph.
    map<int, bool> dfsvisited;
    map<int,bool> visited;
    bool iscycle(int x, vector<int> graph[]){
        visited[x] = true;
        dfsvisited[x] = true;
        for(auto i: graph[x]){
            if(!visited[i] and iscycle(i, graph))return true;
            else if(dfsvisited[i])return true;
        }
        dfsvisited[x] = false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        for(int i = 0; i< V; i++){
            if(!visited[i] and iscycle(i, adj))return true;
        }
        return false;
    }
};

int main(){
    

    return 0;
}