class Graph{
    int v; // number of vertices in a graph
    int n; // number of nodes in a grpah
    vector<vector<int> >edges; // graph which is storing the edges
    vector<int> weights; // weights of the array
    void addedge(int i, int j){
        g[i].push_back(j);
    }
    void bellmanford(){
        vector<int> dis(n, INT_MAX);
        dis[0] = 0;
        for(int i = 0; i<n-1; i++){
            for(int j = 0; j<n; j++){
                dis[edges[j][1]] = min(dis[edges[j][1]], weights[j] + dis[edges[j][0]]);
            }
        }
    }
    // after this you would get the distance array
};