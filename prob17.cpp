#include<bits/stdc++.h>
int uniquePaths(int m,int n){
int N=m+n-2,r=m-1;
int ans=1;
for(int i=0;i<=r;i++){
ans*=(N-r+i)/i;
}
return ans;
}
