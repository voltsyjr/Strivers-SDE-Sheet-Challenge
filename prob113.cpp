#include <bits/stdc++.h> 
int getMaxWidth(TreeNode<int> *root)
{
    if(!root)return 0;
    queue<TreeNode<int>*>q;
    q.push(root);
    int ans=0;
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            TreeNode<int>*node=q.front();
            q.pop();
            if(node->left)q.push(node->left);
            if(node->right)q.push(node->right);
        }
        ans=max(ans,size);
    }
    return ans;
}