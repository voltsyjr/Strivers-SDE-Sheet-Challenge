bool dfs(int node,vector<int>&vis,vector<int>&pos,vector<int>adj[]){
  vis[node]=1;
  pos[node]=1;
  for(auto it:adj[node]){
    if(vis[it]==0){
      if(dfs(it,vis,pos,adj))return true;
    }else if(pos[it]==1)return true;
  }
  pos[node]=0;
  return false;
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  vector<int>adj[n+1];
  for(auto it:edges){
    adj[it.first].push_back(it.second);
  }
  vector<int>vis(n+1,0);
  vector<int>pos(n+1,0);
  for(int i=1;i<=n;i++){
    if(vis[i]==0)
      if(dfs(i,vis,pos,adj))return 1;
  }
  return 0;
}