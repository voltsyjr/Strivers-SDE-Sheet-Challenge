#include<bits/stdc++.h>
int subarraysXor(vector<int>&arr,int x){
unordered_map<int,int>mp;
mp[0]=1;
int xr=0;
int cnt=0;
for(int i=0;i<arr.size();i++){
xr=xr^arr[i];
cnt+=mp[xr^x];
mp[xr]++;
}//end for
return cnt;
}
