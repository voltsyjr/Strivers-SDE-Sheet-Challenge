#include<bits/stdc++.h>
pair<int,int>missingAndRepeating(vector<int>&arr,int n){
long long int rsum=0,rsq=0,sum=n*(n+1)/2,sq=n*(n+1)* (2*n+1)/6;
for(auto it:arr){
rsum+=it;
rsq+=it*it;
}
int m,r;
m=((sq-rsq)/(sum-rsum)+(sum-rsum))/2;
r=m-(sum-rsum);
return {m,r};
}
