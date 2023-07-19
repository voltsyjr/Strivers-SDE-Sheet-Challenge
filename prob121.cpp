#include <bits/stdc++.h> 
void leftBoundary(TreeNode<int>*root,vector<int>&boundary){
    TreeNode<int>*cur=root->left;
    while(cur){
        if(!(cur->left==NULL and cur->right==NULL))
        boundary.push_back(cur->data);
        if(cur->left!=NULL)cur=cur->left;
        else cur=cur->right;
    }
    return;
}
void leafBoundary(TreeNode<int>*root,vector<int>&boundary){
    if(root==NULL)return;
    if(root->left==NULL and root->right==NULL)
        boundary.push_back(root->data);
    leafBoundary(root->left,boundary);
    leafBoundary(root->right,boundary);
}
void rightBoundary(TreeNode<int>*root,vector<int>&boundary){
    TreeNode<int>*cur=root->right;
    vector<int>temp;
    while(cur){
        if(!(cur->left==NULL and cur->right==NULL))
        temp.push_back(cur->data);
        if(cur->right!=NULL)cur=cur->right;
        else cur=cur->left;
    }
    for(int k=temp.size()-1;k>=0;k--){
        boundary.push_back(temp[k]);
    }
    return;
}
vector<int> traverseBoundary(TreeNode<int>* root){
    if(!root)return {};
    vector<int>boundary;
    if(!(root->left==NULL and root->right==NULL))boundary.push_back(root->data);
    leftBoundary(root,boundary);
    leafBoundary(root,boundary);
    rightBoundary(root,boundary);
    return boundary;
}