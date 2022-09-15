//https://www.geeksforgeeks.org/minimum-time-taken-by-each-job-to-be-completed-given-by-a-directed-acyclic-graph//
#include<bits/stdc++.h>
using namespace std;

class graph{
    int v;
    vector<int>g[v];
    vector<int> indegree(v, 0);
    vector<int> minimum_time(v,0);
    vector<bool> visited(v, false);
    void Add_edge(int m, int n){
        v[m].push_back(n);
        indegree[n]++;
    }
    void minimum_time(){
        // surely we would be using the bfs for this purpose here
        queue<int> q;

        // so first we would be adding the numbers which has the indegree equal to zero
        for(int i = 0; i<n; i++){
            if(indegree[i]==0)q.push(i);
        }
        int job = 0;
        while(!q.empty()){
            int len = q.size();
            job++;
            while(len--){
                auto node = q.front();
                visited[node] = true;
                q.pop();
                for(int i:g[node]){
                    if(!visited[i])q.push(i);
                } 
                minimum_time[node] = job;
            }
        }
    }
}







int main(){
    return 0;
}