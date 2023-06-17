Node *findMiddle(Node * head){
int len=0;
Node *ptr=head;
while(ptr!=NULL){
ptr=ptr->next;
len++;
}//end while
len=len/2;
ptr=head;
while(len){
ptr=ptr->next;
len--;
}//end while
return ptr;
}
