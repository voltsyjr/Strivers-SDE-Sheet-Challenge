#include<bits/stdc++.h>
int LongestSubsetWithZeroSum(vector<int>arr){
int k=0;
unordered_map<int,int>mp;
long long sum=0;
int ans=0;
for(int i=0;i<arr.size();i++){
sum+=arr[i];
if(sum==k){ans=max(ans,i+1);}
if(mp.find(sum-k)!=mp.end()){
ans=max(ans,i-mp[sum-k]);
}//end if
if(mp.find(sum)==mp.end())
mp[sum]=i;
}//end for
return ans;
}
