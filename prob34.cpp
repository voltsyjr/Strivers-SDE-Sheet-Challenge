
bool isPalindrome(LinkedListNode<int>*head){
if(!head or head->next==NULL)return true;
LinkedListNode<int>*slow=head,*fast=head;
while(fast!=NULL and fast->next!=NULL and fast->next->next!=NULL){
slow=slow->next;
fast=fast->next->next;
}//end while
fast=slow->next;
LinkedListNode<int>*prev=NULL,*next=NULL;
while(fast){
next=fast->next;
fast->next=prev;
prev=fast;
fast=next;
}//end while
slow->next=prev;
fast=slow->next;
slow=head;
while(fast!=NULL){
if(slow->data != fast->data){
return false;
}else{
slow=slow->next;
fast=fast->next;
}
}//end while
return true;
}