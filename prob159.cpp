void dfs(int i,int j,int **arr,vector<vector<int>>&vis,int n,int m){
   vis[i][j]=1;
   int dirRow[]={0,1,0,-1,-1,-1,1,1};
   int dirCol[]={1,0,-1,0,-1,1,-1,1};
   for(int d=0;d<8;d++){
      int x=i+dirRow[d];
      int y=j+dirCol[d];
      if(x>=0 and x<n and y>=0 and y<m and vis[x][y]==0 and arr[x][y]==1){
         dfs(x,y,arr,vis,n,m);
      }
   }
}
int getTotalIslands(int** arr, int n, int m)
{
   int islands=0;
   vector<vector<int>>vis(n,vector<int>(m,0));
   for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
         if(vis[i][j]==0 and arr[i][j]==1)dfs(i,j,arr,vis,n,m),islands++;
      }
   }
   return islands;
}
