#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class graph{
    int v;
    vector<int> adj[];
    map<int,bool> visited;
    
    bool directed_graph_cycle(){
        vector<int> indegree(v, 0);
        queue<int> q;
        // here we are finding the degree of the node;
        for(int i = 0; i<v; i++){
            for(auto it:adj[i])indegree[it]++;
        }
        // putting the zero element in the queue
        for(auto it:indegree){
            if(it==0)q.push(it);
        }
        // running the while loop until the queue is empty
        vector<int> topo;
        int cnt = 0;
        while (!q.empty())
        {
            auto front= q.front();
            q.pop();
            cn++;
            for(auto it:adj[front]){
                indegree[it]--;
                if(indegree[it]==0)q.push(it);
            }
            topo.push_back(front);
        }
        return cn==v;
    }
}
int main()
{
    
    return 0;
}