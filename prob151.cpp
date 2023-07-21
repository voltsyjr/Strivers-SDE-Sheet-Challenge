void dfs(int node,vector<int>&vis,vector<int>&temp,vector<int>adj[]){
    temp.push_back(node);
    vis[node]=1;
    for(auto it:adj[node]){
        if(vis[it]==0)dfs(it,vis,temp,adj);
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<int>adj[V];
    for(auto it:edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    vector<int>vis(V,0);
    vector<vector<int>>ans;
    for(int i=0;i<V;i++){
        if(vis[i]==0){
            vector<int>temp;
            dfs(i,vis,temp,adj);
            ans.push_back(temp);
        }
    }
    return ans;
}