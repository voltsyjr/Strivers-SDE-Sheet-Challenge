#include <bits/stdc++.h> 
int rec(int i,int j,vector<vector<int>>&grid,int n,int m,vector<vector<int>>&dp){
    if(i==n-1 and j==m-1)return grid[i][j];
    if(i==n or j==m)return INT_MAX;
    if(dp[i][j]!=-1)return dp[i][j];
    return dp[i][j]=grid[i][j]+min(rec(i+1,j,grid,n,m,dp),rec(i,j+1,grid,n,m,dp));
}
int minSumPath(vector<vector<int>> &grid) {
    int n=grid.size(),m=grid[0].size();
    // vector<vector<int>>dp(n,vector<int>(m,-1));
    // return rec(0,0,grid,n,m,dp);
    
    //tabulation
    // vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    // for(int i=0;i<=n;i++)dp[i][m]=INT_MAX;
    // for(int j=0;j<=m;j++)dp[n][j]=INT_MAX;
    // for(int i=n-1;i>=0;i--){
    //     for(int j=m-1;j>=0;j--){
    //         if(i==n-1 and j==m-1){dp[i][j]= grid[i][j];continue;}
    //         dp[i][j]=grid[i][j]+min(rec(i+1,j,grid,n,m,dp),rec(i,j+1,grid,n,m,dp));
    //     }
    // }
    // return dp[0][0];

    //space optimization
    vector<int>next(m+1,INT_MAX),cur(m+1,INT_MAX);
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(i==n-1 and j==m-1){cur[j]= grid[i][j];continue;}
            cur[j]=grid[i][j]+min(next[j],cur[j+1]);        
        }
        next=cur;
    }
    return next[0];
}