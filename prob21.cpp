#include<bits/stdc++.h>
int lengthOfLongestConsecutiveSequence(vector<int>&arr,int n){
unordered_set<int>s;
for(auto it:arr){s.insert(it);}
int c=0,ans=0;
for(auto it:s){
if(s.find(it-1)==s.end()){
c=1;
while(s.find(it+1)!=s.end()){c++;it=it+1;}
ans=max(ans,c);
}
}
return ans;
}
