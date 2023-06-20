#include<bits/stdc++.h>
void rec(vector<int>&num,vector<int>&ans,int i,int s,int n){
if(i>=n){ans.push_back(s); return;}
rec(num,ans,i+1,s,n);
rec(num,ans,i+1,s+num[i],n);
}
vector<int>subsetSum(vector<int>&num){
vector<int>ans;
rec(num,ans,0,0,num.size());
sort(ans.begin(),ans.end());
return ans;
}
