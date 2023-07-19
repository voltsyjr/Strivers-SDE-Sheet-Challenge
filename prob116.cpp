int rec(TreeNode<int>*root,int&maxi){
        if(!root)return 0;
        int lh=rec(root->left,maxi);
        int rh=rec(root->right,maxi);
        maxi=max(maxi,lh+rh);
        return 1+max(lh,rh);
    }
int diameterOfBinaryTree(TreeNode<int> *root)
{
	int maxi=0;
    rec(root,maxi);
    return maxi;
}
