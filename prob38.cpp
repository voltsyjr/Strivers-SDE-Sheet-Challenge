LinkedListNode<int>*cloneRandomList(LinkedListNode<int>*head){
unordered_map<LinkedListNode<int>*,LinkedListNode<int>*>mp;
LinkedListNode<int>*newHead=new LinkedListNode<int>(-1),*ptr1=head,*ptr2=NULL;
ptr2=newHead;
while(ptr1!=NULL){
LinkedListNode<int>*newNode=new LinkedListNode<int>(ptr1->data);
ptr2->next=newNode;
mp[ptr1]=newNode;
ptr1=ptr1->next;
ptr2=ptr2->next;
}
ptr1=head;
while(ptr1!=NULL){
mp[ptr1]->random=mp[ptr1->random];
ptr1=ptr1->next;
}//end while
return newHead->next;
}