#include <bits/stdc++.h> 
void dfs(int node,vector<int>&vis,stack<int>&st,vector<int>adj[]){
    vis[node]=1;
    for(auto it:adj[node]){
        if(vis[it]==0)dfs(it,vis,st,adj);
    }
    st.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<int>adj[v];
    stack<int>st;
    for(auto it:edges){
        adj[it[0]].push_back(it[1]);
    }
    vector<int>vis(v,0);
    for(int i=0;i<v;i++){
        if(vis[i]==0)dfs(i,vis,st,adj);
    }
    vector<int>topo;
    while(!st.empty()){
        topo.push_back(st.top());
        st.pop();
    }
    return topo;
}