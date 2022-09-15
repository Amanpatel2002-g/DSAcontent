#define push_back pb
#include <bits/stdc++.h>
using namespace std;

class graph
{
    int n;
    vector<vector<int>> edges;
    int arr[n] = { -1 };
public:
    graph(int i){n=i;} // consturctor

    void addedge(int a,int b){ // this is a way to addedge in the graph
        vector<int> temp;
        temp.pb(i), temp.pb(j);
        edges.pb(temp);
    }

    int getparent(int i){
        if(arr[i]==-1)return i;
        int temp = i;
        arr[temp] = getparent(arr[i]);
        return i;
    }

    int find(int i, int j){ // this is a way to find that element lies in the same set or not;
        i = getparent(i);
        j = getparent(j);
        if(i==j)return i;
        return -1;
    }
    void Union(int i, int j){
        i = getparent(i);
        j = getparent(j);
        arr[i] = j;
    }
    bool iscycle(){
        for(auto &i:edges){
            int a = i[0], b = i[1];
            if(find(a,b)==-1)Union(a,b);
            else return true;
        }
        return false;
    }
}

int
main()
{
    return 0;
}