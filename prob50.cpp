#include <bits/stdc++.h> 
void rec(vector<int>&arr,set<vector<int>>&s,int i,int n,vector<int>&t){
if(i>=n){
    sort(t.begin(),t.end());
    s.insert(t);
    return;
}
t.push_back(arr[i]);
rec(arr,s,i+1,n,t);
for(int j=0;j<t.size();j++){
    if(t[j]==arr[i]){
        t.erase(t.begin()+j);
        break;
    }
}
rec(arr,s,i+1,n,t);
}
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    set<vector<int>>s;
    vector<int>t;
    rec(arr,s,0,n,t);
    vector<vector<int>>ans;
    for(auto it:s){
        ans.push_back(it);

    }
    return ans;
}