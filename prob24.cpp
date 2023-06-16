#include<bits/stdc++.h>
int uniqueSubstrings(string input){
vector<int>mp(256,-1);
int l=0,r=0,n=input.length(),ans=0;
while(r<n){
char c=input[r];
if(mp[c]!=-1)l=max(l,mp[c]+1);
mp[c]=r;
ans=max(ans,r-l+1);
r++;
}//end while
return ans;
}
