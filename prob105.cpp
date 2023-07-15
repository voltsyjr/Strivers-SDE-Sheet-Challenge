#include <bits/stdc++.h> 
void preorder(vector<int>&ans,TreeNode*root){
    if(root==NULL)return;
    ans.push_back(root->data);
    preorder(ans,root->left);
    preorder(ans,root->right);
}
vector<int> getPreOrderTraversal(TreeNode *root)
{
    if(root==NULL)return {};
    vector<int>ans;
    preorder(ans,root);
    return ans;
}