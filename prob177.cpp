
int rec(int i,int remRod,vector<int>&price,vector<vector<int>>&dp){
	if(i==0)return price[0]*remRod;
	if(dp[i][remRod]!=-1)return dp[i][remRod];
	int rodLen=i+1;//of ith index size
	int notTake=rec(i-1,remRod,price,dp),take=INT_MIN;
	if(rodLen<=remRod)take=price[i]+rec(i,remRod-rodLen,price,dp);
	return dp[i][remRod]=max(take,notTake);
}
int cutRod(vector<int> &price, int n)
{
	// vector<vector<int>>dp(n,vector<int>(n+1,-1));
	// return rec(n-1,n,price,dp);
	// tabulation

	// vector<vector<int>>dp(n,vector<int>(n+1,0));
	// for(int i=0;i<=n;i++)dp[0][i]=price[0]*(i);
	// for(int i=1;i<n;i++){
	// 	for(int remRod=0;remRod<=n;remRod++){
	// 		int rodLen=i+1;//of ith index size
	// 		int notTake=dp[i-1][remRod],take=INT_MIN;
	// 		if(rodLen<=remRod)take=price[i]+dp[i][remRod-rodLen];
	// 		dp[i][remRod]=max(take,notTake);
	// 	}
	// }
	// return dp[n-1][n];


	//space optimization
	vector<int>prev(n+1,0),cur(n+1,0);
	for(int i=0;i<=n;i++)prev[i]=i*price[0];
	for(int i=1;i<n;i++){
		for(int remRod=0;remRod<=n;remRod++){
			int rodLen=i+1;//of ith index size
			int notTake=prev[remRod],take=INT_MIN;
			if(rodLen<=remRod)take=price[i]+cur[remRod-rodLen];
			cur[remRod]=max(take,notTake);
		}
		prev=cur;
	}
	return prev[n];
}
