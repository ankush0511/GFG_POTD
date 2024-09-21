
Node *temp=head;
Node *hcopy=new Node(0);
Node *tcopy=hcopy;
//normaly singly LL created
while(temp)
{
    tcopy->next=new Node(temp->data);
    tcopy=tcopy->next;
    temp=temp->next;
}
tcopy=hcopy;
hcopy=hcopy->next;
delete hcopy;

tcopy=hcopy;
Node * curr=head;
//use unordered_map to store the original and duplicate LL node address 
unordered_map<Node *,Node *>m;
while(curr) {
    m[curr]=tcopy;
    tcopy=tcopy->next;
    curr=curr->next;
}
temp=head;
tcopy=hcopy;
while(temp) {
//duplicate ka random pointer points to the original LL arbitrary pointet
//it came. to know with the help of unordered map
    tcopy->random=m[temp->random];
    tcopy=tcopy->next;
    temp=temp->next;
}

return hcopy;




    