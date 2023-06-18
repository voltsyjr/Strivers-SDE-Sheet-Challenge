Node *firstNode(Node*head){
if(!head or head->next==NULL)return NULL;
Node *slow=head,*fast=head;
do{
slow=slow->next;
fast=fast->next->next;
}while(slow!=fast and slow and fast and fast->next!=NULL);
if(fast==NULL or fast->next==NULL)return NULL;
fast=head;
while(slow!=fast and slow and fast){
slow=slow->next;
fast=fast->next;
}
return fast;
}