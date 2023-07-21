#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    vector<pair<int,int>>adj[vertices];
    for(auto it:vec){
        adj[it[0]].push_back({it[1],it[2]});
        adj[it[1]].push_back({it[0],it[2]});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,source});
    vector<int>dist(vertices,INT_MAX);
    vector<int>parent(vertices);
    dist[source]=0;
    for(int i=0;i<vertices;i++)parent[i]=i;
    while(!pq.empty()){
        int comingDist=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        for(auto it:adj[node]){
            int wt=comingDist+it.second;
            if(wt<dist[it.first]){
                dist[it.first]=wt;
                parent[it.first]=node;
                pq.push({wt,it.first});
            }
        }
    }
    return dist;
}
