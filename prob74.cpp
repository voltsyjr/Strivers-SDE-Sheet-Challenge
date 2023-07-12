vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    unordered_map<int,int>mp;
    for(auto it:arr)mp[it]++;
    priority_queue<pair<int,int>>mxheap;
    for(auto it:mp){
        mxheap.push({it.second,it.first});
    }
    vector<int>ans;
    for(int i=0;i<k;i++){
        auto it=mxheap.top();
        mxheap.pop();
        ans.push_back(it.second);
    }
    return ans;
}