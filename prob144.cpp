#include <bits/stdc++.h> 
void flatten(BinaryTreeNode<int>*root,BinaryTreeNode<int>*&prev){
    if(!root)return;
    flatten(root->right,prev);
    root->right=prev;
    if(root->right)root->right->left=root;
    prev=root;
    flatten(root->left,prev);
}
BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    BinaryTreeNode<int>*prev=NULL;
    flatten(root,prev);
    return prev;
}