// ways to show the graph
#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include<vector>
class graph{
    // This graph would be the undirected graph
    int n; // number of the edges
    map<int, vector<int>> m;// to use the adjacent matrix;
public:
    graph(int a, vector<vector<int>> v1){
        n = a;
        for(int i = 0; i<v1.size(); i++){
            m[v1[i][0]].push_back(v1[i][1]);
        }
    } 
    // Now we would be writing the code for the dfs and bfs
    void dfs_helper(int x, map<int, bool>&visited){
        cout<<x<<endl;
        visited[x] = true; // declaring that we have visited the node ;
        if(m.find(x)!=m.end()){
            for(auto i:m[x]){
                if(!visited[i]) dfs_helper(i,visited);
            }
            
        }
    }
    void dfs(){
        map<int, bool> visited;
        if(m.begin() != m.end()){
            visited[m.begin()->first] = true;
        }
        for(auto i = visited.begin(); i!=visited.end(); i++){
            for(auto i = m.begin(); i!=m.end(); i++){
                if (!visited[i->first])
                {
                    dfs_helper(i->first, visited);
                }
                for(auto x: i->second){
                    if(!visited[x]) dfs_helper(x, visited);
                }
            }
        }
    }
    void bfs(){
        queue<int> q;
        map<int, bool> visited;
        if(m.begin() != m.end()){
            q.push(m.begin()->first);
            visited[m.begin()->first] = true;
            while(!q.empty()){
                int x = q.front();
                cout << x << endl;
                q.pop();
                visited[x] = true;
                if(m.find(x)!=m.end()){
                    for (int i: m[x])
                    {
                        if(!visited[i])q.push(i); 
                    }
                    
                }
            }
        }
        else{
            cout<<"Please fill the graph"<<endl;
        }
    }
    // Now we would be writing
};
int main()
{
    vector<vector<int>> v;
    int n;
    cin>>n;
    for (int i = 0; i <n ; i++)
    {
        int x, y;
        cin>>x>>y; 
        vector<int> v1;
        v1.push_back(x);
        v1.push_back(y);
        v.push_back(v1);
    }
    cout<<"--------------------The solution starts from here-------------------"<<endl;
    graph g(n,v);
    g.bfs();
    return 0;
}
