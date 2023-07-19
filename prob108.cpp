#include <bits/stdc++.h> 
vector<int> bottomView(BinaryTreeNode<int> * root){
    queue<pair<BinaryTreeNode<int>*,int>>q;
    q.push({root,0});
    map<int,int>mp;
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        mp[it.second]=it.first->data;
        if(it.first->left)q.push({it.first->left,it.second-1});
        if(it.first->right)q.push({it.first->right,it.second+1});
    }
    vector<int>bottomView;
    for(auto it:mp){
        bottomView.push_back(it.second);
    }
    return bottomView;
}
