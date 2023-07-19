bool isSym(BinaryTreeNode<int>*p,BinaryTreeNode<int>*q){
    if(!p or !q)return p==q;//if both NULL return true else false;
    if(p->data==q->data)
        return isSym(p->left,q->right) and isSym(p->right,q->left);
    return false; 
}
bool isSymmetric(BinaryTreeNode<int>* root)
{
    if(!root)return true;
    return isSym(root->left,root->right);  
}