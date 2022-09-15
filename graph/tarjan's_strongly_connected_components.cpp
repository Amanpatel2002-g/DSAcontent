#include<bits/stdc++.h>
using namespace std;
class graph{
    // it's a directed graph and tarjan's algo only work for it
    int n;
    int v;
    vector<vector<int>> G ;
    void addedge(int i, int j) {
        vector<int> temp = {i, j};
        G.push_back(temp);
    }
    void tarjan(int i, vector<int>&low, vector<int>&dis, vector<bool>&instack, stack<int> &mystack;){
        mystack.push(i);
        instack[i] = true;
        static time t = 0;
        low[i] = dis[i] = t;
        t++; // incrementing the time;
        for(int &j:G[i]){
            if(low[j]==-1){
                tarjan(j, low,dis,instack,mystack);
                low[i] = min(low[i],low[j]);
            }
            else if(instack[j]){
                low[i] = min(low[i], dis[j]);
            }
        }

        // checking for the root edge
        if(low[i]==dis[i]){
            cout<<"SCC is: ";
            while(mystack.top()!=i){
                cout<<mystack.top()<<" ";
                instack[mystack.top()] = false;
                mystack.pop();
            }
            cout<<mystack.top()<<" ";
            instack[mystack.top()] = false;
            mystack.pop();
            cout<<endl;
        }

    }
    void dfs(){
        vector<int>low(n, -1), dis(n, -1);
        vector<bool> instack(n, false);
        stack<int> mystack;
        for(int i = 0; i<n; i++){
            if(low[i]==-1)tarjan(i, low, dis, instack);
        }
    }
}
int main(){


    return 0;
}