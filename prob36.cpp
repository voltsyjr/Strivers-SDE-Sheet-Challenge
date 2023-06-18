Node *flat(Node* head){
	if(head->next==NULL or head==NULL){
		return head;
	}
	// cout<<head->data<<"called"<<endl;
	Node *h2=flat(head->next);
	// cout<<h2->data<<"ret"<<endl;
	Node *ptr1=head,*ptr2=h2;
	Node *newHead=new Node(-1);
	Node *ptr=newHead;
	while(ptr1!=NULL or ptr2!=NULL){
		if(ptr1!=NULL and ptr2!=NULL){
			if(ptr1->data<ptr2->data){
				ptr->next=ptr1;
				ptr->child=ptr1;
				ptr1=ptr1->child;
				ptr=ptr->next;
			}else{
				ptr->next=ptr2;
				ptr->child=ptr2;
				ptr2=ptr2->child;
				ptr=ptr->next;
			}
		}else if(ptr1!=NULL){
			ptr->next=ptr1;
			ptr->child=ptr1;
			ptr1=ptr1->child;
				ptr=ptr->next;
		}else if(ptr2!=NULL){
			ptr->next=ptr2;
			ptr->child=ptr2;
				ptr2=ptr2->child;
				ptr=ptr->next;	
		}
	}
	ptr->next=NULL;
	ptr->child=NULL;
	// cout<<newHead->next->data<<" returned"<<endl;
	return newHead->next;
}