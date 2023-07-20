#include <bits/stdc++.h> 
void changeTree(BinaryTreeNode < int > * root) {
    if(!root)return;
    int child=0;
    if(root->left)child+=root->left->data;
    if(root->right)child+=root->right->data;
    if(child<root->data){
        if(root->left)root->left->data=root->data;
        else if(root->right)root->right->data=root->data;
    }
    changeTree(root->left);
    changeTree(root->right);
    int recTop=0;
    if(root->left)recTop+=root->left->data;
    if(root->right)recTop+=root->right->data;
    if(root->left or root->right)
        root->data=recTop;
}  