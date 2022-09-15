// the graph which can be coloured using exactly two colours is known as bipartite graph
// we are doing this with the help of bfs. we have already done this with the help of dfs in geeks for geeks
class graph{
    int n;
    vector<int>g[n];
    void addedge(int k, int i, int j){
        g[i].push_back(j);
    }
    bool bipartite(){
        queue<int> q;
        q.push(0);
        int col = 0;
        vector<int>colored(n, -1);
        while(!q.empty()){
            int size = q.size();
            auto node  = q.front();
            q.pop();
            col = 1 - colored[node];
            for(int i:g[node]){
                if(colored[i] ==-1){
                    colored[i] = col;
                    q.push(i); 
                }
                else if(colored[i]!=col)return false;
            }
        }
        return true;
    }
}

