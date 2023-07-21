#include<bits/stdc++.h>
bool dfs(int node,vector<int>adj[],vector<int>&vis,int parent){
    vis[node]=1;
    for(auto it:adj[node]){
        if(it==parent)continue;
        if(vis[it]==1)return true;
        else{
            if(dfs(it,adj,vis,node))return true;
        }
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<int>adj[n+1];
    for(auto it:edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    vector<int>vis(n+1);
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            if(dfs(i,adj,vis,-1))return "Yes";
        }
    }
    return "No";
}
