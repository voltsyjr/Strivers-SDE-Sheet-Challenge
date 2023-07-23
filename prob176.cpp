#include <bits/stdc++.h> 
bool targetSum(int ind,int target,vector<int>&arr,vector<vector<int>>&dp){
    if(target==0)return true;
    if(ind==0)return arr[0]==target;
    if(dp[ind][target]!=-1)return dp[ind][target];
    bool notTake=targetSum(ind-1,target,arr,dp);
    bool take=false;
    if(arr[ind]<=target)take=targetSum(ind-1,target-arr[ind],arr,dp);
    return dp[ind][target]=take|notTake;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // vector<vector<int>>dp(n,vector<int>(k+1,-1));
    // return targetSum(n-1,k,arr,dp);

    //tabulation
    // vector<vector<bool>>dp(n+1,vector<bool>(k+1,false));
    // for(int i=0;i<n;i++)dp[i][0]=true;
    // dp[0][arr[0]]=true;
    // for(int ind=1;ind<n;ind++){
    //     for (int target = 1; target <= k; target++) {
    //         bool notTake = dp[ind - 1][target];
    //         bool take = false;
    //         if (arr[ind] <= target)take=dp[ind-1][target-arr[ind]];
    //         dp[ind][target]=take|notTake;
    //     }
    // }
    // return dp[n-1][k];


    //space optimization
    vector<bool>prev(k,false),cur(k+1,false);
    prev[0]=cur[0]=true;
    prev[arr[0]]=true;
    for(int ind=1;ind<n;ind++){
        for (int target = 1; target <= k; target++) {
            bool notTake = prev[target];
            bool take = false;
            if (arr[ind] <= target)take=prev[target-arr[ind]];
            cur[target]=take|notTake;
        }
        prev=cur;
    }
    return prev[k];

}