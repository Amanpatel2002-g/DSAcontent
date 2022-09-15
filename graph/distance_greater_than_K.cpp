#include<bits/stdc++.h>
using namespace std;
class graph{
        int v;
        map<int,vector<pair<int,int>>> G;
public:
    graph(){}
    graph(int x){v = x;}
    map<int,bool> visited;
    void addEdge(int i, int j, int price){
        G[i].push_back({j, price});
        G[j].push_back({i, price});
    }
    bool pathmorethank(int node, int sum, int k){
        visited[node] = true;
        // cout<<sum<<endl;
        if(sum>=k)return true;
        for(auto j:G[node]){
            if(!visited[j.first]){
                if(pathmorethank(j.first,sum+j.second, k)==true)return true;
            }
        }
        visited[node] = false;
        return false;
    }
};
int main(){
    graph g(9);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
    cout<<g.pathmorethank(0,0,58)<<endl;
    return 0;
}