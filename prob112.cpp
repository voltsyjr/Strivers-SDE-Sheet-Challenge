#include <bits/stdc++.h> 
bool rec(TreeNode<int>*root,vector<int>&path,int x){
	if(!root)return false;
	path.push_back(root->data);
	if(root->data==x)return true;
	if(rec(root->left,path,x))return true;
	if(rec(root->right,path,x))return true;
	path.pop_back();
	return false;
}
vector<int> pathInATree(TreeNode<int> *root, int x)
{
    vector<int>path;
	if(rec(root,path,x))return path;
	return {};
}
