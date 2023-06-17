bool detectCycle(Node *head){
if(!head)return false;
Node *s=head,*f=head->next;
while(s!=NULL and f!=NULL and f->next!=NULL and s!=f)s=s->next,f=f->next->next;
if(s==NULL or f==NULL or f->next==NULL)return 0;
return 1;
}