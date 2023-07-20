#include <bits/stdc++.h> 
class nodeVal{
public:
    int minVal,maxVal,size;
    nodeVal(int mn,int mx,int s){
        minVal=mn,maxVal=mx,size=s;
    }
};
nodeVal largestSizeBST(TreeNode<int>*root){
    if(!root)return nodeVal(INT_MAX,INT_MIN,0);
    nodeVal left=largestSizeBST(root->left);
    nodeVal right= largestSizeBST(root->right);
    if(left.maxVal<root->data and right.minVal>root->data){
        return nodeVal(min(left.minVal,root->data),
        max(right.maxVal,root->data),left.size+right.size+1);
    }
    return nodeVal(INT_MIN,INT_MAX,max(left.size,right.size));
}
int largestBST(TreeNode<int>* root) {
    return largestSizeBST(root).size;    
}
