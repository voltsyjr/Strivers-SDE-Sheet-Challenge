
Node * findIntersection(Node* firstHead,Node *secondHead){
int l1=0,l2=0;
Node *ptr1=firstHead,*ptr2=secondHead;
while(ptr1)l1++,ptr1=ptr1->next;
while(ptr2)l2++,ptr2=ptr2->next;
if(l2>l1)swap(firstHead,secondHead),swap(l2,l1);
int d=l1-l2;
ptr1=firstHead,ptr2=secondHead;
while(d--)ptr1=ptr1->next;
while(ptr1 and ptr2){
if(ptr1==ptr2)return ptr1;
ptr1=ptr1->next;
ptr2=ptr2->next;
}//end while
return NULL;
}
