#include<bits/stdc++.h>
vector<vector<int>>findTriplets(vector<int>arr,int n,int k){
vector<vector<int>>ans;
sort(arr.begin(),arr.end());
int i=0;
while(i<n-3){
int l=i+1,r=n-1;
while(l<r){
	long long sum=arr[i]+arr[l]+arr[r];
if(sum==k){
ans.push_back({arr[i],arr[l],arr[r]});
while(l<r and arr[l]==arr[l+1])l++;
l++;
while(r>l and arr[r]==arr[r-1])r--;
r--;
}//end if
else if(sum<k){
while(l<r and arr[l]==arr[l+1])l++;
l++;
}//end else if
else{
while(r>l and arr[r]==arr[r-1])r--;
r--;
}//end else
}

while(i<n-3 and arr[i]==arr[i+1])i++;
i++;
}
return ans;
}
