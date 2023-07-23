#include <bits/stdc++.h> 
int rec(int ind,int prev,vector<int>&rack,vector<vector<int>>&dp){
	if(ind==rack.size())return 0;
	if(dp[ind][prev+1]!=-1)return dp[ind][prev+1];
	int notTake=rec(ind+1,prev,rack,dp);
	int take=INT_MIN;
	if(prev==-1 or rack[ind]>rack[prev])
		take=rack[ind]+rec(ind+1,ind,rack,dp);
	return dp[ind][prev+1]=max(take,notTake);
}
int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
	// vector<vector<int>>dp(n,vector<int>(n+1,-1));
	// return rec(0,-1,rack,dp);

	//tabulation
	// vector<vector<int>>dp(n+1,vector<int>(n+1,0));
	// //base case nth index already zero
	// for(int ind=n-1;ind>=0;ind--){
	// 	for(int prev=ind-1;prev>=-1;prev--){
	// 		int notTake=dp[ind+1][prev+1];
	// 		int take=INT_MIN;
	// 		if(prev==-1 or rack[ind]>rack[prev])
	// 			take=rack[ind]+dp[ind+1][ind+1];
	// 		dp[ind][prev+1]=max(take,notTake);
	// 	}
	// }
	// return dp[0][-1+1];

	//space optimization
	vector<int>next(n+1,0),cur(n+1,0);
	//base case nth index already zero
	for(int ind=n-1;ind>=0;ind--){
		for(int prev=ind-1;prev>=-1;prev--){
			int notTake=next[prev+1];
			int take=INT_MIN;
			if(prev==-1 or rack[ind]>rack[prev])
				take=rack[ind]+next[ind+1];
			cur[prev+1]=max(take,notTake);
		}
		next=cur;
	}
	return next[-1+1];
}