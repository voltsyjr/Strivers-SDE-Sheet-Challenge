#include <bits/stdc++.h> 
void inorder(vector<int>&ans,TreeNode*root){
    if(root==NULL)return;
    inorder(ans,root->left);
    ans.push_back(root->data);
    inorder(ans,root->right);
}
vector<int> getInOrderTraversal(TreeNode *root)
{
    if(root==NULL)return {};
    vector<int>ans;
    inorder(ans,root);
    return ans;
}