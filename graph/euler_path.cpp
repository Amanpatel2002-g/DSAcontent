// https://www.youtube.com/watch?v=WY6Jsp3NxIk
// Above is the source for reading 
#include<bits/stdc++.h>
using namespace std;
class graph{
    int v;
    map<int, vector<int>> G;
public:
    graph(int x){v = x;}
    void addedge(int i, int j){
        m[i].push_back(j);
        m[j].push_back(i);
    }
    void DFS(int i, vector<int>&visited){
        visited[i] = true;
        for(auto it:adj[i]){
            if(!visited[it])DFS(it,visited);
        }
    }
    bool is_connected(){
        vector<bool> visited(V+1, false);
        int node = -1;
        for(int i = 0;i<v; i++){
            if(adj[i].size()>0)node = i; break;
        }
        if(node==-1)return true;
        DFS(node,visited);
        for(int i =0; i<v; i++){
            if(!visited[i] and adj[i].size()>0)return false;
        }
        return true;
    }

    int find_euler(){
        if(!connected_graph())return 0;

    //   checking for the odd degree condition
        int odd = 0;
        for(int i = 0; i<v; i++){
            if(G[i].size() & 1){
                odd++;
            }
        }
        if(odd>2)return 0;
        if(odd==0)?2:1;
        return 0;
    }
};


int main(){
    int x = 7&7;
    cout<<x<<endl;
    return 0;
}