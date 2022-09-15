#include <bits/stdc++.h>
using namespace std;

class GraphClass
{
private:
    int v;
    map<int, vector<int>> graph;
public:
    GraphClass(int noOfNodes){
        v = noOfNodes;
    }
    void addEdge(int m, int n){
        graph[m].push_back(n);
        graph[n].push_back(m);
    }
    
    bool isValidColor(int node, int color, vector<int>&colorOfNodes){
        for(auto nbh:graph[node]){
            if(colorOfNodes[nbh]==color)return false;
        }
        return true;
    }

    bool Mcoloring(int node, int m, vector<int>&colorOfNodes){
        for(int i = 0; i<m; i++){
            if(isValidColor(node, i, colorOfNodes)){
                colorOfNodes[node] = i;
                bool isAnyUncolored = false;
                for(int j:graph[node]){
                    if(colorOfNodes[j]==-1){
                        isAnyUncolored = true;
                        if(Mcoloring(j, m, colorOfNodes))return true;
                        else break;
                    }
                }
                if(!isAnyUncolored){
                    return true;
                }
            }
        }
        return false;
    }

    bool MColoringProblem(int m){
        vector<int> colorOfNodes(v, -1);
        return Mcoloring(0, m,colorOfNodes);
    }
};

int main()
{
    GraphClass g(3);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(0,2);
    cout<<g.MColoringProblem(2)<<endl;
    return 0;
}