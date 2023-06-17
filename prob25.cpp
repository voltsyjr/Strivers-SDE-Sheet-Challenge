#include<bits/stdc++.h>
LinkedListNode<int>*reverseLinkedList(LinkedListNode<int>*head){
if(!head)return NULL;
LinkedListNode<int> *ptr=NULL,*prev=NULL;
ptr=head;
prev=NULL;
while(ptr!=NULL){
LinkedListNode<int> *temp=NULL;
temp=ptr->next;
ptr->next=prev;
prev=ptr;
ptr=temp;
}//end while
return prev;
}
