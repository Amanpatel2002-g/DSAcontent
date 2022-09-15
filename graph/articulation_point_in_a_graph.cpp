// this link is here for the reference https://www.geeksforgeeks.org/articulation-points-or-cut-vertices-in-a-graph/
// this is the vedio link for the in techdoes https://www.youtube.com/watch?v=64KK9K4RpKE


#include<bits/stdc++.h>
using namespace std;

class Graph{
    int v; // number of vertices in a graph
    int n; // number of nodes in a grpah
    vector<int> g[n]; // to store the edges
    int time = 0; // discovery time variable
    void addedge(int i, int j){
        g[i].push_back(j);
    }
    void articulate(int i, vector<int>&parent,vector<int>&dis, vector<int>&low, vector<bool> art){
        dis[i] = low[i] = t;
        t++;
        int child = 0;
        for(int j:g[i]){
            if(j!=parent[i]){
                if(low[j]==-1){
                    child++;
                    parent[j] = i;
                    articulate(j, parent,dis, low, art);
                    low[i] = min(low[i], low[j]);
                    if(low[j]>=dis[i])art[i] = true;
                }
                else{
                    low[i] = min(low[i], dis[j]);
                }
            }
        }
        if(parent[i]==-1 and child>1)art[i] = true;
    }
    void dfs(){
        vector<int> parent(n, -1), dis(n, -1), low(n, -1);
        vector<bool> art(n, false);
        for(int i = 0; i < n; i++){
            if(low[i]==-1){
                articulate(i, parent, dis, low, art);
            }
        }
    }

};



int main(){
    return 0;
}