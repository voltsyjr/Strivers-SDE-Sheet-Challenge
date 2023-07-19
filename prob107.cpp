#include <bits/stdc++.h> 
void left(vector<int>&leftView,TreeNode<int>*root,int level){
    if(!root)return ;
    if(level==leftView.size())leftView.push_back(root->data);
    left(leftView,root->left,level+1);
    left(leftView,root->right,level+1);
    return;
}
vector<int> getLeftView(TreeNode<int> *root)
{
    if(root==NULL)
      return {};
    vector<int>leftView;
    left(leftView,root,0);
    return leftView;
}