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
