#include <bits/stdc++.h> 
bool isPalindrome(string &s,int l,int r){
    while(l<=r){
        if(s[l]!=s[r])return false;
        l++,r--;
    }
    return true;
}
int rec(int i,int j,string &str,vector<vector<int>>&dp){
    if(i==j or isPalindrome(str,i,j))return 0;
    
    if(dp[i][j]!=-1)return dp[i][j];
    int mini=INT_MAX;
    for(int k=i;k<=j-1;k++){
        mini=min(mini,1+rec(i,k,str,dp)+rec(k+1,j,str,dp));
    }
    return dp[i][j]=mini;
}
int palindromePartitioning(string str) {
    int n=str.size();
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    return rec(0,n-1,str,dp);
}
