#include<bits/stdc++.h>
TreeNode<int>*buildTree(vector<int>&postOrder,int postStart,int postEnd,vector<int>&inOrder,
int inStart,int inEnd,unordered_map<int,int>&mp){
     if(postStart>postEnd or inStart>inEnd)return NULL;
     TreeNode<int>* root=new TreeNode<int>(postOrder[postEnd]);
     int curRoot=mp[postOrder[postEnd]];
     int numsRightSide=inEnd-curRoot;
     root->right=buildTree(postOrder,postEnd-numsRightSide,postEnd-1,
     inOrder,curRoot+1,inEnd,mp);
     root->left=buildTree(postOrder,postStart,postEnd-numsRightSide-1,
     inOrder,inStart,curRoot-1,mp);
     return root;
}
TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
	unordered_map<int,int>mp;
     for(int i=0;i<inOrder.size();i++)mp[inOrder[i]]=i;
     TreeNode<int>* root=buildTree(postOrder,0,postOrder.size()-1,inOrder,0,inOrder.size()-1,mp);
     return root;
}
