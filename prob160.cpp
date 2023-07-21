bool dfs(int node,vector<int>adj[],vector<int>&col){
	for(auto it:adj[node]){
		if(col[it]==-1){
			if(col[node]==0)col[it]=1;
			else col[it]=0;
			if(!dfs(it,adj,col))return false;
		}else if(col[it]==col[node])return false;
	}
	return true;
}
bool isGraphBirpatite(vector<vector<int>> &edges) {
	int n=edges.size();
	vector<int>col(n,-1);
	vector<int>adj[n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(edges[i][j]==1)adj[i].push_back(j);
		}
	}
	for(int i=0;i<n;i++){
		if(col[i]==-1){
			col[i]=0;
			if(!dfs(i,adj,col))return false;
		}
	}
	return true;
}