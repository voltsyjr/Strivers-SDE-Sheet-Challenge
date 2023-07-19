#include <bits/stdc++.h> 
vector<int> getTopView(TreeNode<int> *root) {
    if(!root)return {};
    queue<pair<TreeNode<int>*,int>>q;
    map<int,int>mp;
    q.push({root,0});
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        if(mp.find(it.second)==mp.end())mp[it.second]=it.first->val;
        if(it.first->left)q.push({it.first->left,it.second-1});
        if(it.first->right)q.push({it.first->right,it.second+1});
    }
    vector<int>topView;
    for(auto it:mp)topView.push_back(it.second);
    return topView;
}