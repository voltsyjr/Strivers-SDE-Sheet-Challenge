#include <bits/stdc++.h> 
void ksmall(TreeNode<int>*root,int&kk,int &ans){
    if(kk<=0 or !root)return;
    ksmall(root->left,kk,ans);
    kk--;
    if(kk==0)ans=root->data;
    ksmall(root->right,kk,ans);
}
int kthSmallest(TreeNode<int> *root, int k)
{
	int kk=k;
    int ans=0;
    ksmall(root,kk,ans);
    return kk<=0?ans:-1;
}