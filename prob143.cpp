#include<bits/stdc++.h>
string serializeTree(TreeNode<int> *root){
    if(!root)return "";
    string s="";
    queue<TreeNode<int>*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode<int>* curNode=q.front();
        q.pop();
        if(!curNode)s+="#,";
        else s+=to_string(curNode->data)+",";
        if(curNode){
            q.push(curNode->left);
            q.push(curNode->right);
        }
    }
    return s;
}

TreeNode<int>* deserializeTree(string &serialized){
    if(serialized.size()==0)return NULL;
    queue<TreeNode<int>*>q;
    stringstream s(serialized);
    string str;
    getline(s,str,',');
    TreeNode<int>*root=new TreeNode<int>(stoi(str));
    q.push(root);
    while(!q.empty()){
        TreeNode<int>*node=q.front();
        q.pop();
        getline(s,str,',');
        if(str!="#"){
            node->left=new TreeNode<int>(stoi(str));
            q.push(node->left);
        }
        getline(s,str,',');
        if(str!="#"){
            node->right=new TreeNode<int>(stoi(str));
            q.push(node->right);
        }
    }
    return root;

}



