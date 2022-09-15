#include<bits/stdc++.h>
using namespace std;
class graph{
    private:
        int v;
        map<int,vector<pair<int,int>>> G;
    public:
        graph(int x){v =x;}
        map<int,int> dis;
        // function to add the function
        void addedge(int i, int j){
            G[i].push_back({j,0});
            G[j].push_back({i,1});
        }
        void dijkstra(int src,int des){
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
            for(int i = 0; i<v; i++){
                dis[i] = INT_MAX;
            }
            dis[src] = 0;
            pq.push({0,src});
            while(!pq.empty()){
                int node_u = pq.top().second;
                int dis_u = pq.top().first;
                pq.pop();
                for(auto node:G[node_u]){
                    int node_v = node.first;
                    int weight = node.second;
                    if(dis[node_v]>dis_u+weight){
                        dis[node_v] = dis_u + weight;
                        pq.push({dis[node_v],node_v});
                    }
                }
            }
            cout<<dis[des]<<endl;
        }
};
int main(){
    int V = 7;
    graph g(V);
 
    int edges[][2] = {{0, 1}, {2, 1}, {2, 3}, {5, 1}, {4, 5}, {6, 4}, {6, 3}};
    for(int i = 0; i<7; i++){
        g.addedge(edges[i][0],edges[i][1]);
    }
    g.dijkstra(0,6);
    return 0;
}