#include<bits/stdc++.h>
void rec(vector<vector<int>>&ans,vector<int>&temp,vector<int>&arr,int ind,int target,int n){
if(target==0){
ans.push_back(temp);
return;
}
for(int i=ind;i<n;i++){
if(i!=ind and arr[i]==arr[i-1])continue;
if(arr[i]>target)break;
temp.push_back(arr[i]);
rec(ans,temp,arr,i+1,target-arr[i],n);
temp.pop_back();
}
}
vector<vector<int>>combinationSum2(vector<int>&arr,int n,int target){
vector<vector<int>>ans;
vector<int>temp;
sort(arr.begin(),arr.end());
rec(ans,temp,arr,0,target,n);
// vector<vector<int>>ans2(ans.begin(),ans.end());
return ans;
}
