#include <bits/stdc++.h> 

bool identicalTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    if(!root1 and !root2)return true;
    if(!root1 or !root2)return false;
    return root1->data==root2->data and identicalTrees(root1->left,root2->left)
     and identicalTrees(root1->right,root2->right);	 
}