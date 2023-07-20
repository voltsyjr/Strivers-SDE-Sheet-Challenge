#include <bits/stdc++.h> 
void predecessor(BinaryTreeNode<int>*root,int &p,int key){
    if(!root)return;
    if(root->data<key){
        p=max(p,root->data);
        predecessor(root->right,p,key);
    }else{
        predecessor(root->left,p,key);
    }
}
void successor(BinaryTreeNode<int>*root,int &s,int key){
    if(!root)return;
    if(root->data>key){
        s=min(s,root->data);
        successor(root->left,s,key);
    }else{
        successor(root->right,s,key);
    }
}
pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    int p=INT_MIN,s=INT_MAX;
    predecessor(root,p,key);
    successor(root,s,key);
    return {p==INT_MIN?-1:p,s==INT_MAX?-1:s};
}
