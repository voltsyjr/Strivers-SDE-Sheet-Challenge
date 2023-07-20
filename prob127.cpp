#include <bits/stdc++.h> 
bool pathToLeaf(TreeNode<int>*root,TreeNode<int>*leaf,stack<TreeNode<int>*>&st){
    if(root==NULL)return false;
    st.push(root);
    if(root->data==leaf->data)return true;
    if(pathToLeaf(root->left,leaf,st))return true;
    if(pathToLeaf(root->right,leaf,st))return true;
    st.pop();
    return false;
}
TreeNode<int> * invertBinaryTree(TreeNode<int> *root, TreeNode<int> *leaf)
{
	stack<TreeNode<int>*>st;
    pathToLeaf(root,leaf,st);
    TreeNode<int>*newRoot=st.top(),*parent=NULL;
    st.pop();
    parent=newRoot;
    while(!st.empty()){
        TreeNode<int>* curNode=st.top();
        st.pop();
        if(curNode->left!=parent){
            curNode->right=curNode->left;
        }
        curNode->left=NULL;
        parent->left=curNode;
        parent=curNode;
    }
    return newRoot;
}
