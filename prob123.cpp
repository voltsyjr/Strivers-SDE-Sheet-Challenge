#include <bits/stdc++.h> 
TreeNode<int>* buildTree(int preStart,int preEnd,int inStart,
int inEnd,vector<int>&preorder,vector<int>&inorder,unordered_map<int,int>&mp){
    if(preStart>preEnd or inStart>inEnd)return NULL;
    int curRoot=preorder[preStart];
    TreeNode<int>* root=new TreeNode<int>(curRoot);
    int numsLeft=mp[curRoot]-inStart;
    root->left=buildTree(preStart+1,preStart+numsLeft,inStart,inStart+numsLeft-1,
    preorder,inorder,mp);
    root->right=buildTree(preStart+numsLeft+1,preEnd,inStart+numsLeft+1,inEnd,
    preorder,inorder,mp);
    return root;
}
TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	unordered_map<int,int>mp;
    for(int i=0;i<inorder.size();i++)mp[inorder[i]]=i;
    int preStart=0,inStart=0,preEnd=preorder.size()-1,inEnd=inorder.size();
    TreeNode<int>*root=buildTree(preStart,preEnd,inStart,inEnd,preorder,inorder,mp);
    return root;
}