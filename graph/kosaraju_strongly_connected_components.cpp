// in an undirected graph (unless the graph is not having the multiple components) 
// we can say that the entire graph can be strongly connected
// kosaraju algorithm helps you to find the number of strongly connected components

// on reversing the edges the type of graph wouldn't change 
// the graph would also be the strongly connected if it was SCC before as well
// this is the property due to which kosaraju algorithm is working ()
#include<bits/stdc++.h>
using namespace std;

class graph{
    int v; // number of edges in a graph    
    int n; // number of nodes in graph
    map<int, vector<int>> g;
    map<int, vector<int>> rev;
    vector<bool> visited(n, false);
    void addedge(int i, int j){
        vector<int> temp = {i,j};
        g.push_back(temp);
    }
    void dfs1(int i, stack<int>&mystack){
        visited[i] = true;
        mystack.push_back(i);
        for(int j:g[i]){
            if(!visited[j])dfs1(j,mystack);
        }
        st.push(i);
    }
    void reverse(){
        for(int i = 0; i<v; i++){
            for(int j: g[i]){
                rev[j].push_back(i);
            }
        }
    }
    

    void dfs2(int i){
        visited[i] = true;
        for(int j:g[i]){
            if(!visited[j])dfs2(j);
        }
    }

    void kosaraju(){
        stack<int> mystack;
        for(int i = 0; i<n; i++){
            if(!visited[i])dfs1(i,mystack);
        }
        for(int i = 0;i<n; i++)visited[i] = false;


        // reversing the graph(transposing the graph)
        reverse();
        int count = 0;
        while(!st.empty()){
            if(!visited[st.top()]){
                count++;
                dfs2(st.top());
            }
            st.pop();// pop from the stack

        }
    }
}



int main(){
    return 0;
}