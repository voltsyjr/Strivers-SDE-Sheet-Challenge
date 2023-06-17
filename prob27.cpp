
Node<int>*sortTwoLists(Node<int>*first,Node<int>*second){
if(!first and !second)return NULL;
if(!first)return second;
if(!second)return first;
Node<int> *newHead=NULL,node(-1);
newHead=&node;
Node<int> *ptr1=first,*ptr2=second,*ptr3=newHead;
while(ptr1!=NULL and ptr2!=NULL){
if(ptr1->data<ptr2->data){
ptr3->next=ptr1;
ptr1=ptr1->next;
}else{
ptr3->next=ptr2;
ptr2=ptr2->next;
}//end else
ptr3=ptr3->next;
}//end while
while(ptr2!=NULL){
    ptr3->next=ptr2;
    ptr2=ptr2->next;
    ptr3=ptr3->next;
}
while(ptr1!=NULL){
    ptr3->next=ptr1;
    ptr1=ptr1->next;
    ptr3=ptr3->next;
}
ptr3->next=NULL;
ptr1=newHead->next;
while(ptr1!=NULL){cout<<(ptr1->data)<<" ";ptr1=ptr1->next;}
return NULL;
}
