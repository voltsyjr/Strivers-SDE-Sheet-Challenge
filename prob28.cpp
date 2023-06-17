Node* removeKthNode(Node *head,int k){
if(!head)return head;
int len=0;
Node* ptr=head;
while(ptr!=NULL)len++,ptr=ptr->next;
len=len-k;
Node *prev=NULL;
ptr=head;
if(len==0)return head->next;
while(len){
prev=ptr;
ptr=ptr->next;
len--;
}
prev->next=ptr->next;
return head;
}