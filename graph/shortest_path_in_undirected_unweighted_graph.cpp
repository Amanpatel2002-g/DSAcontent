#include <bits/stdc++.h>
#include<iostream>
using namespace std;
// undirected Graph
class Graph
{
    int v;
    map<int, vector<int>> graph;
public:
    Graph(int x){
        v = x;
    }
    void addEdge(int x, int y)
    {
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    void shortestDistanceFromSourceNode(int src)
    {
        vector<int> distance(v, INT_MAX);
        distance[src] = 0;
        queue<int> q;
        q.push(src);
        while (!q.empty())
        {
            auto srcc = q.front();
            q.pop();
            auto dis = distance[srcc];
            for (auto node : graph[srcc])
            {
                if (dis + 1 < distance[node]){
                    distance[node] = dis + 1;
                    q.push(node);
                }
            }
        }
        int j = 0;
        for(auto i:distance){
            cout<<"distance of the node "<< j << " is from source node is: "<<i<<endl;
            j++;
        }
    }

};

int main(){
        int V = 9;
    Graph g(V);
 
    //  making above shown graph
    g.addEdge(0, 1);
    g.addEdge(0, 7);
    g.addEdge(1, 2);
    g.addEdge(1, 7);
    g.addEdge(2, 3);
    g.addEdge(2, 8);
    g.addEdge(2, 5);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.addEdge(6, 7);
    g.addEdge(6, 8);
    g.addEdge(7, 8);
 
    g.shortestDistanceFromSourceNode(0);
    return 0;
}