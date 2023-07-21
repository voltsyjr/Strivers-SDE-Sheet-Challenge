#include<bits/stdc++.h>
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<int>adj[n+1];
    for(auto it:edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    queue<pair<int,int>>q;
    vector<int>vis(n+1);
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            vis[i]=1;
            q.push({i,-1});
            while(!q.empty()){
                int node=q.front().first;
                int parent=q.front().second;
                q.pop();
                for(auto it:adj[node]){
                    if(it==parent)continue;
                    if(vis[it]==1)return "Yes";
                    else{
                        vis[it]=1;
                        q.push({it,node});
                    }
                }
            }
        }
    }
    return "No";
}
