#include <bits/stdc++.h> 
int relax(vector<vector<int>>&edges,vector<int>&dist){
    int r=0;
    for(auto it:edges){
        int u=it[0],v=it[1],wt=it[2];
        if(dist[u]!=1e9 and dist[u]+wt<dist[v]){
            dist[v]=dist[u]+wt;
            r=1;
        }
    }
    return r;
}
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<int>dist(n+1,1e9);
    dist[src]=0;
    for(int i=0;i<n-1;i++){
        relax(edges,dist);
    }
    if(relax(edges,dist))return -1;
    return dist[dest];
}