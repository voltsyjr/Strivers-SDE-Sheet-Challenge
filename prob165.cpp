#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m,
 vector<pair<pair<int, int>, int>> &g)
{
    priority_queue<pair<int,pair<int,int>>,
    vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    pq.push({0,{1,-1}});
    vector<pair<pair<int,int>,int>>ans;
    vector<pair<int,int>>adj[n+1];
    for(auto it:g){
        adj[it.first.first].push_back({it.first.second,it.second});
        adj[it.first.second].push_back({it.first.first,it.second});
    }
    vector<int>vis(n+1,0);
    while(!pq.empty()){
        int node=pq.top().second.first;
        int wt=pq.top().first;
        int parent=pq.top().second.second;
        pq.pop();
        if(vis[node]==1)continue;
        vis[node]=1;
        if(parent!=-1)ans.push_back({{parent,node},wt});
        for(auto it:adj[node]){
            if(vis[it.first]==0){
                pq.push({it.second,{it.first,node}});
            }
        }
    }
    return ans;
}
