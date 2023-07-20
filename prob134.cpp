#include <bits/stdc++.h> 
TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q){
    if(!root)return NULL;
    int mmin=min(P->data,Q->data),mmax=max(P->data,Q->data);
	if(root->data>=mmin and root->data<=mmax)return root;
    if(root->data>mmin)return LCAinaBST(root->left,P,Q);
    return LCAinaBST(root->right,P,Q);
}
