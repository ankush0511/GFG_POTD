
//1 st approach simple brute force 
Node *temp=head;
int count=0;
while(temp) {
    count++;
    temp=temp->next;
}
temp=head;
count/=2;
while(count--)
{
    temp=temp->next;
}
return temp->data;


//2 nd approach using 2 pointer
Node*fast=head,*slow=head;
while(fast->next->next!=NULL&&fast->next!=NULL)
{
slow=slow->next;
fast=fast->next->next;
}

 if(fast->next==NULL) 
 return slow->data;
 else
 return slow->next->data;