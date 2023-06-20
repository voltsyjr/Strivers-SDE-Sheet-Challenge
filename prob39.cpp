#include<bits/stdc++.h>
long getTrappedWater(long *arr,int n){
long l=0,r=n-1,lm=0,rm=0,ans=0;
while(l<=r){
if(arr[l]<=arr[r]){
if(arr[l]>=lm)lm=arr[l];
else ans+=lm-arr[l];
l++;
}//end if
else{
if(arr[r]>=rm)rm=arr[r];
else ans+=rm-arr[r];
r--;
}//end else
}//end while
return ans;
}
