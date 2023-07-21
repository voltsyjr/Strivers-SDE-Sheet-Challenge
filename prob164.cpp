int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<vector<int>>dist(n,vector<int>(n,1e9));
    for(int i=0;i<n;i++)dist[i][i]=0;
    for(auto it:edges){
        dist[it[0]-1][it[1]-1]=it[2];
    }
    for(int via =0;via<n;via++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dist[i][via]!=1e9 and dist[via][j]!=1e9)
                    dist[i][j]=min(dist[i][j],dist[i][via]+dist[via][j]);
            }
        }
    }
    return dist[src-1][dest-1];
}