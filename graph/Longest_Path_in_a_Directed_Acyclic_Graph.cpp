// for reference purpose you can refer to the https://www.geeksforgeeks.org/find-longest-path-directed-acyclic-graph/

class Graph{
    // this is the directed graph 
    int v; // number of vertices in a graph
    int n; // number of nodes in a grpah
    vector<int> g[n]; // to store the edges
    bool visited[n] = { false }; // initializing the array in c++
    void addedge(int i, int j){
        g[i].push_back(j);
    }
    // using the topological sort for this purpose;
    void toposort(int i, stack<int> st){
        visited[i] = true;
        for(int j:g[i]){
            if(!visited[j]){
                toposort(j, st);
            }
        }
        st.push(i);
    }
    void toposortdfs(){
        stack<int> st;
        for(int i = 0; i<n;i++){
            if(!visited[i])toposort(i, st);
        }
    }
    // we would be using the dijkhistra algorithm for this task

    while(!st.empty()){
        
    }
    
};