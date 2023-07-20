#include <bits/stdc++.h> 
void klarge(TreeNode<int>*root,int &kk,int &ans){
    if(kk<=0 or !root)return;
    klarge(root->right,kk,ans);
    kk--;
    if(kk==0)ans=root->data;
    klarge(root->left,kk,ans);
}
int KthLargestNumber(TreeNode<int>* root, int k) {
    int kk=k,ans=0;
    klarge(root,kk,ans);
    return kk<=0?ans:-1;
}
