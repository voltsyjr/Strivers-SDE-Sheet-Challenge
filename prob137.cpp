#include <bits/stdc++.h> 
void successor(BinaryTreeNode<int>*root,int &s,int key){
    if(!root)return;
    if(root->data>=key){
        s=min(s,root->data);
        successor(root->left,s,key);
    }else{
        successor(root->right,s,key);
    }
}
int findCeil(BinaryTreeNode<int> *node, int x){
    int s=INT_MAX;
    successor(node,s,x);
    return s==INT_MAX?-1:s;
}x