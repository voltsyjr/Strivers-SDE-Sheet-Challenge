#include <bits/stdc++.h> 
int isBal(BinaryTreeNode<int>*root){
    if(!root)return 0;
    int l=isBal(root->left);
    int r=isBal(root->right);
    if(l==-1 or r==-1)return -1;
    if(abs(l-r)>1)return -1;
    return 1+max(l,r);
}
bool isBalancedBT(BinaryTreeNode<int>* root) {
    int isBalanced=isBal(root);
    if(isBalanced==-1)return false;
    return true;
}