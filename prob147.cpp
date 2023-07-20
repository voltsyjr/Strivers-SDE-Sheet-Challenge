#include <bits/stdc++.h> 
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    int i=0,j=0,size=arr.size();
    vector<int>ans;
    unordered_map<int,int>mp;
    while(j<size){
        mp[arr[j]]++;
        if(j-i+1<k)j++;
        else{
            if(j-i+1==k)ans.push_back(mp.size());
            mp[arr[i]]--;
            if(mp[arr[i]]==0)mp.erase(arr[i]);
            i++,j++;
        }
    }
    return ans;
}
