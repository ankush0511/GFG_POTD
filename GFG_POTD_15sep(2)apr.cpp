class Solution {
public:
    Node *head=NULL,*ln=NULL;
    //inoder travel
    void helper(Node *root) {
        if(!root) return;
        helper(root->left);
        //ans store ki jagah ham LL mai convert karenge
        //head i.e 1 elements of inorder traversal
        //head not exist means 1 wala elements hai wo
        if(!head)head=root;
        //last node hai jo root ka left rahege
        if(ln)ln->right=root;
        //previous wala ko point karo root
        root->left=ln;
        //pointer update karo
        ln=root;
        helper(root->right);
    }
    Node* bToDLL(Node* root) {
        // code here
        helper(root);

        return head;
    }
};



/*
***APPROACH 2 ***
THAT HAS SPACE COMPLEXITY =>O(N)*/
class Solution {
  public:
  void inorder(Node * root, vector<int>&ans)
{
    if(!root)
        return;
    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
}
    Node* bToDLL(Node* root) {
        // code here
        vector<int>ans;
inorder(root,ans);
//cout<<ans.size();
Node *curr=new Node(0);
Node * p=curr;
//curr->left=NULL;
//curr->right=NULL;
for(int i=0;i<ans.size();i++){
Node *temp=new Node(ans[i]);
temp->left=curr;
curr->right=temp;
curr=temp;
}
p=p->right;
p->left=NULL;
return p;

