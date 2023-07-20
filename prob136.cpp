#include <bits/stdc++.h> 
void predecessor(TreeNode<int>*root,int &p,int key){
    if(!root)return;
    if(root->val<=key){
        p=max(p,root->val);
        predecessor(root->right,p,key);
    }else{
        predecessor(root->left,p,key);
    }
}
int floorInBST(TreeNode<int> * root, int X)
{
    int p;
    predecessor(root,p,X);
    return p==INT_MIN?-1:p;
}