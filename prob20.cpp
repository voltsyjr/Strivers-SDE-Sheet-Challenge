#include<bits/stdc++.h>
string fourSum(vector<int> arr,int target,int n){
sort(arr.begin(),arr.end());
int i=0;
while(i<n-3){
int j=i+1;
while(j<n-2){
int s=arr[i]+arr[j];
int l=j+1,r=n-1;
while(l<r){
if(s+arr[l]+arr[r]==target){
return "Yes";
while(l<r-1 and arr[l]==arr[l+1])l++;
l++;
while(r>l and arr[r]==arr[r-1])r--;
r--;
}else if(s+arr[l]+arr[r]<target){
while(l<r-1 and arr[l]==arr[l+1])l++;
l++;
}else{
while(r>l and arr[r]==arr[r-1])r--;
r--;
}
}//binary search end
while(j<n-2 and arr[j]==arr[j+1])j++;
j++;
}//second while end
while(i<i-3 and arr[i]==arr[i+1])i++;
i++;
}//first while end
return "No";
}
