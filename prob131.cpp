#include <bits/stdc++.h> 
TreeNode<int>* BST(vector<int>&arr,int l,int r){
    if(l>r)return NULL;
    int m=(l+r)>>1;
    TreeNode<int>*root=new TreeNode<int>(arr[m]);
    root->left=BST(arr,l,m-1);
    root->right=BST(arr,m+1,r);
    return root;
}
TreeNode<int>* sortedArrToBST(vector<int> &arr, int n){
    return BST(arr,0,n-1);
}