#include<bits/stdc++.h>
long rec(int i,int * denominations,int n,int value,vector<vector<long>>&dp){
    if(value==0)return 1;
    if(i==n)return 0;
    if(dp[i][value]!=-1)return dp[i][value];
    long take=0;
    if(denominations[i]<=value)
        take=rec(i,denominations,n,value-denominations[i],dp);
    long notTake=rec(i+1,denominations,n,value,dp);
    return dp[i][value]=take+notTake;
}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>>dp(n,vector<long>(value+1,-1));
    return rec(0,denominations,n,value,dp);

    tabulations
    vector<vector<long>>dp(n+1,vector<long>(value+1,0));
    for(int j=0;j<=value;j++)dp[n][j]=0;
    for(int i=0;i<=n;i++)dp[i][0]=1;
    for(int i=n-1;i>=0;i--){
        for(int val=0;val<=value;val++){
            long take=0;
            if(denominations[i]<=val)
                take=dp[i][val-denominations[i]];
            long notTake=dp[i+1][val];
            dp[i][val]=take+notTake;
        }
    }
    return dp[0][value];


    //space optimization
    vector<long>next(value+1,0),cur(value+1,0);
    for(int i=n-1;i>=0;i--){
        next[0]=cur[0]=1;
        for(int val=0;val<=value;val++){
            long take=0;
            if(denominations[i]<=val)
                take=cur[val-denominations[i]];
            long notTake=next[val];
            cur[val]=take+notTake;
        }
        next=cur;
    }
    return next[value];
}