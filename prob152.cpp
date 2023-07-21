#include <bits/stdc++.h> 
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    set<int>adj[vertex];
    for(auto it:edges){
        adj[it.first].insert(it.second);
        adj[it.second].insert(it.first);
    }
    queue<int>q;
    vector<int>ans;
    vector<int>vis(vertex,0);
    for(int i=0;i<vertex;i++){
        if(vis[i]==0){
            q.push(i);
            vis[i]=1;
            while(!q.empty()){
                int node=q.front();
                q.pop();
                ans.push_back(node);
                for(auto it:adj[node]){
                    if(vis[it]==0){
                        q.push(it);
                        vis[it]=1;
                    }
                }
            }
        }
    }
    return ans;
}