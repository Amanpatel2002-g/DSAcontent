#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class graph{
    int v;
    vector<int> adj[];
    map<int, bool> visited;
    vector<int> topo;
    stack<int> st;
    void toposort_helper_dfs(int x){
        visited[x]=true;
        for(auto it:adj[i]){
            if(!visited[it])toposort_helper_dfs(it);
        }
        st.push(x);
    }
    void toposort_dfs(){
        for(int i = 0; i<v; i++){
            if(!visited[i])toposort_helper_dfs(i);
        }
        while(!st.empty()){
            topo.push_back(st.top()); 
            st.pop();
        }
    }
};
int main()
{
    
    return 0;
}
