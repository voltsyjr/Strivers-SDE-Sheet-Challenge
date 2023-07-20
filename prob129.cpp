class Solution {
public:
    Node* connect(Node* root) {
        if(!root)return NULL;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            Node*prev=NULL,*next=NULL;
            for(int i=0;i<size;i++){
                next=q.front();
                q.pop();
                if(next->left)q.push(next->left);
                if(next->right)q.push(next->right);
                if(i==0){prev=next;continue;}
                prev->next=next;
                prev=next;
            }
            prev->next=NULL;
        }
        return root;
    }
};