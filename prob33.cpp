Node *reverseList(Node *head,int i,int b[],int n){
if(head==NULL)return NULL;
if(i>=n){return head;}
Node*prev=NULL,*cur=head,*next=NULL;
int k=b[i];
if(k==0)return reverseList(head,i+1,b,n);
while(k-- and cur!=NULL){
next=cur->next;
cur->next=prev;
prev=cur;
cur=next;
}//end while
head->next=reverseList(cur,i+1,b,n);
return prev;
}
Node *getListAfterReverseOperation(Node* head,int n,int b[]){
return reverseList(head,0,b,n);
}