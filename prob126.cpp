#include <bits/stdc++.h> 
void preFlat(TreeNode<int>* root,TreeNode<int>* &prev){
    if(!root)return ;
    preFlat(root->right,prev);
    preFlat(root->left,prev);
    root->right=prev;
    root->left=NULL;
    prev=root;
}
TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    TreeNode<int>*prev=NULL;
    preFlat(root,prev);
    return prev;
}