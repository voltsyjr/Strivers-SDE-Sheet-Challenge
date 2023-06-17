Node* addTwoNumbers(Node *num1,Node* num2){
int c=0;
Node *num=NULL,*nd=new Node(-1);
num=nd;
while(num1!=NULL or num2!=NULL or c){
    int sum=0;
    if(num1!=NULL)sum+=num1->data,num1=num1->next;;
    if(num2)sum+=num2->data,num2=num2->next;
    sum+=c;
    Node *newNode = new Node(sum%10);
    num->next=newNode;
    num=num->next;
    c=sum/10;
}
return nd->next;
}