#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>mnheap;
    vector<int>ind(k,0);
    for(int i=0;i<k;i++) mnheap.push({kArrays[i][0],i});
    vector<int>ans;
    while(!mnheap.empty()){
        auto it=mnheap.top();
        mnheap.pop();
        ans.push_back(it.first);
        if(ind[it.second]+1<kArrays[it.second].size())
            mnheap.push({kArrays[it.second][ind[it.second]+1],it.second}),ind[it.second]++;
    }
    return ans;
}
