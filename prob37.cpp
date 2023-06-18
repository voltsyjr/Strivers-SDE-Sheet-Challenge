Node *rotate(Node *head,int k){
int len=0;
Node*ptr=head;
while(ptr->next)len++,ptr=ptr->next;
k=k%(len+1);
ptr->next=head;
Node *ptr2=head;
len=len-k;
while(len--)ptr2=ptr2->next;
head=ptr2->next;
ptr2->next=NULL;
return head;

}