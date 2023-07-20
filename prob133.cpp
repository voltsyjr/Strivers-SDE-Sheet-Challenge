#include <bits/stdc++.h> 
bool valid(BinaryTreeNode<int>*root,int lb,int ub){
    if(!root)return true;
    if(root->data<lb or root->data>ub)return false;
    if(!valid(root->left,lb,root->data))return false;
    if(!valid(root->right,root->data,ub))return false;
    return true;
}
bool validateBST(BinaryTreeNode<int> *root) {
    return valid(root,INT_MIN,INT_MAX);
}