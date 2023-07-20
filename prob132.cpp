#include <bits/stdc++.h> 
TreeNode<int>*BST(vector<int>&preorder,int &i,int ub){
    if(i==preorder.size() or preorder[i]>ub)return NULL;
    TreeNode<int>*root = new TreeNode<int>(preorder[i++]);
    root->left=BST(preorder,i,root->data);
    root->right=BST(preorder,i,ub);
    return root;
}
TreeNode<int>* preOrderTree(vector<int> &preOrder){
    int i=0;
    return BST(preOrder,i,INT_MAX);
}