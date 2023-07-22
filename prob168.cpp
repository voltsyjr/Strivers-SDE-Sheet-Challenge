#include<bits/stdc++.h>
int seq(int arr[],int n,int ind,int prevInd,vector<vector<int>>&dp){
    if(ind==n)return 0;
    if(dp[ind][prevInd+1]!=-1)return dp[ind][prevInd+1];
    int notTake=seq(arr,n,ind+1,prevInd,dp),take=0;
    if(prevInd==-1 or arr[ind]>arr[prevInd])take=1+seq(arr,n,ind+1,ind,dp);
    return dp[ind][prevInd+1]=max(take,notTake);
}
int longestIncreasingSubsequence(int arr[], int n)
{
    // vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    // // return seq(arr,n,0,-1,dp);
    // for(int ind=n-1;ind>=0;ind--){
    //     for(int prevInd=ind-1;prevInd>=-1;prevInd--){
    //         int notTake=dp[ind+1][prevInd+1],take=0;
    //         if(prevInd==-1 or arr[ind]>arr[prevInd])take=1+dp[ind+1][ind+1];
    //         dp[ind][prevInd+1]=max(take,notTake);
    //     }
    // }
    vector<int>next(n+1,0),cur(n+1,0);
    for(int ind=n-1;ind>=0;ind--){
        for(int prevInd=ind-1;prevInd>=-1;prevInd--){
            int notTake=next[prevInd+1],take=0;
            if(prevInd==-1 or arr[ind]>arr[prevInd])take=1+next[ind+1];
            cur[prevInd+1]=max(take,notTake);
        }
        next=cur;
    }
    return next[-1+1];
}
