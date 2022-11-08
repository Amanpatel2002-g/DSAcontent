// Check if a given graph is tree or not
#include<bits/stdc++.h>
using namespace std;

class Graph{
    int n;
    map<int,vector<int>> graph;
    Graph(int n){
        this->n = n;
    }
    void addedge(int i, int j){
        graph[i].push_back(j);
        graph[j].push_back(i);
    }
    bool dfs(int i, int prev, map<int,bool>&visited){
        for(int node:graph[i]){
            if(prev!=node and !visited[node]){
                visited[node] = true;
                bool ans = dfs(node, i, visited);
                if(!ans)return false;
            }
            else if(prev!=node and visited[node]){
                return false;
            }
        }
        return true;
    }
    bool istree(){
        // using dfs traversal
        // cycle to nahi he?
        map<int,bool> visited;
        return !dfs(0, -1, visited);
    }
};


int main(){
    return 0;
}