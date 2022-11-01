#include <bits/stdc++.h>
using namespace std;

class Graph
{
// This is the directed graph 
private:
    int v;
    map<int, vector<int>> graphMap;

public:
    void addEdge(int i, int j){
        graphMap[i].push_back(j);
    }

    void components(int currNode, vector<bool>&visited){
        visited[currNode] = true;
        for(auto node: graphMap[currNode]){
            if(!visited[i])components(node, visited);
        }
    }

    int NoOfComponents(){
        vector<bool>visited(v, false);
        int count = 0;
        for (int i = 0; i < v; i++)
        { 
            if(!visited[i]){
                count++;
                components(i, visited);
            }
        }
        return count;
        
    }

};
