// referecne links https://www.geeksforgeeks.org/minimum-edges-reverse-make-path-source-destination/
/* 1) Initialize distances of all vertices as infinite.

2) Create an empty priority_queue pq.  Every item
   of pq is a pair (weight, vertex). Weight (or 
   distance) is used  as first item  of pair
   as first item is by default used to compare
   two pairs

3) Insert source vertex into pq and make its
   distance as 0.

4) While either pq doesn't become empty
    a) Extract minimum distance vertex from pq. 
       Let the extracted vertex be u.
    b) Loop through all adjacent of u and do 
       following for every vertex v.

           // If there is a shorter path to v
           // through u. 
           If dist[v] > dist[u] + weight(u, v)

               (i) Update distance of v, i.e., do
                     dist[v] = dist[u] + weight(u, v)
               (ii) Insert v into the pq (Even if v is
                    already there)
               
5) Print distance array dist[] to print all shortest
   paths.  */

#include<bits/stdc++.h>
using namespace std;
class Graph{
    int v;
    map<int, vector<pair<int,int>>>G;
public:
    Graph(int x){v=x;} // this is to set the number of nodes
    map<int,int> dis; // map this distance
    void addEdge(int x, int y, int price){
        G[x].push_back({y,price});
        G[y].push_back({x,price});
    } // to add the edge


    void shortest_distance_from_src(){
        cout<<"node"<<"         "<<"distance from source"<<endl;
        for(auto i = dis.begin(); i!=dis.end(); i++){
            cout<<i->first<<"-------------------->"<<i->second<<endl;
        }
    }

    void dijkstra(int src){
        priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq; // here we would be storing the <dis,node>in the array
        for(int i = 0; i<v; i++){dis[i]=INT_MAX;}
        dis[src] = 0;
        pq.push({0,src});

        while (!pq.empty())
        {
            int dist_u = pq.top().first;
            int node_u = pq.top().second;
            pq.pop();

            for(auto node:G[node_u]){
                int node_v = node.first;
                int weight = node.second;
                if(dis[node_v]>dist_u + weight){
                    dis[node_v] = dist_u + weight;
                    pq.push({dis[node_v], node_v});
                }
            }
        }
        shortest_distance_from_src(); 
    }




};

int main(){
        int V = 9;
    Graph g(V);
 
    //  making above shown graph
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
 
    g.dijkstra(0);
    return 0;
}