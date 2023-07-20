#include <bits/stdc++.h> 
class BSTIterator{
public:
    stack<BinaryTreeNode<int>*>st;
    BSTIterator(BinaryTreeNode<int>*root,int s){
        if(s==0)
            pushAll(root);
        else 
            pushAllBefore(root);
    }
    int next(){
        BinaryTreeNode<int>*node=st.top();
        st.pop();
        pushAll(node->right);
        return node->data;
    }
    int before(){
        BinaryTreeNode<int>*node=st.top();
        st.pop();
        pushAllBefore(node->left);
        return node->data;
    }
private:
    void pushAll(BinaryTreeNode<int>*node){
        while(node){
            st.push(node);
            node=node->left;
        }
    }
    void pushAllBefore(BinaryTreeNode<int>*node){
        while(node){
            st.push(node);
            node=node->right;
        }
    }
};
bool pairSumBst(BinaryTreeNode<int> *root, int k){
    BSTIterator * next=new BSTIterator(root,0), *before=new BSTIterator(root,1);
    int i=next->next(),j=before->before();
    while(i<j){
        if(i+j==k)return true;
        else if(i+j<k) i=next->next();
        else j=before->before();
    }
    return false;
}