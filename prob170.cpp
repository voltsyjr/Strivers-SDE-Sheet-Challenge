#include<bits/stdc++.h>
int knapsack(int ind,int w,vector<int>&values,vector<int>&weights,vector<vector<int>>&dp){
	if(ind==-1)return 0;
	if(dp[ind][w]!=-1)return dp[ind][w];
	int notTake=knapsack(ind-1,w,values,weights,dp);
	int take=INT_MIN;
	if(weights[ind]<=w)take=values[ind]+knapsack(ind-1,w-weights[ind],values,weights,dp);
	return dp[ind][w]=max(take,notTake);
}
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	vector<vector<int>>dp(n,vector<int>(w+1,-1));
	return knapsack(n-1,w,values,weights,dp);
	vector<vector<int>>dp(n+1,vector<int>(w+1,0));
	// base case already 0 for -1 index which is shifted as 0
	for(int ind=1;ind<=n;ind++){
          for (int wt = 0; wt <= w; wt++) {
            int notTake = dp[ind - 1][wt];
            int take = INT_MIN;
            if (weights[ind - 1] <= wt)
              take = values[ind - 1] + dp[ind - 1][wt - weights[ind - 1]];
            dp[ind][wt] = max(take, notTake);
          }
        }
	return dp[n][w];


	//space optimization
	vector<int>prev(w+1,0),cur(w+1,0);
	// base case already 0 for -1 index which is shifted as 0
	for(int ind=1;ind<=n;ind++){
          for (int wt = 0; wt <= w; wt++) {
            int notTake = prev[wt];
            int take = INT_MIN;
            if (weights[ind - 1] <= wt)
              take = values[ind - 1] + prev[wt - weights[ind - 1]];
            cur[wt] = max(take, notTake);
          }
		  prev=cur;
        }
	return prev[w];
}