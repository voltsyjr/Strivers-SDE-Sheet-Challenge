void check(TreeNode<int>*root,int &leafs){
    if(root==NULL)return ;
    if(root->left==NULL and root->right==NULL)leafs++;
    check(root->left,leafs);
    check(root->right,leafs);
}
long long int findMaxSumPath(TreeNode<int> *root){
    int maxi=0,leafs=0;
    check(root,leafs);
    if(leafs<=1)return -1;
    rec(root,maxi);
    return maxi;
}
