#include<iostream>
using namespace std;
class Node {
public:
    int data, height;
    Node *left,*right;

    Node (int value) {
        data=value;
        height=1;
        left=right=NULL;

    }
};
int getheight(Node *root) {
    if(!root)
        return 0;
    return root->height;
}
int getbalance(Node *root) {
    return getheight(root->left)-getheight(root->right);
}
Node *rightrotation(Node *root) {
    Node *child=root->left;
    Node *childright=child->right;
    child->right=root;
    root->left=childright;
    root->height=1+max(getheight(root->left),getheight(root->right));
    child->height=1+max(getheight(child->left),getheight(child->right));
    return child;
}

Node *leftrotation(Node *root) {
    Node*child=root->right ;
    Node*childleft=child->left;
    child->left=root;
    root->right=childleft;
    root->height=1+max(getheight(root->left),getheight(root->right));
    child->height=1+max(getheight(child->left),getheight(child->right));
    return child;
}
Node *insert(Node *root,int key) {
    if(!root)
        return new Node(key);
//tree exists
    if(key<root->data)
        root->left=insert(root->left,key);
    else if(key>root->data)
        root->right=insert(root->right,key);
    else
        return root;


    root->height=1+(max(getheight(root->left),(getheight(root->right))));
    int balance= getbalance(root);

//left left case
    if(balance>1&&key<root->left->data)
        return rightrotation(root);
//right right case
    else if(balance<-1&&root->right->data<key)
        return leftrotation(root);
//right left case
    else if(balance<-1&&root->right->data>key) {
        root->right=rightrotation(root->right);
        return leftrotation(root);
    }

//left right case
    else if(balance>1&&key>root->left->data) {
        root->left=leftrotation(root->left);
        return rightrotation(root);
    }
//balanced
    else
        return root;

}

void inorder(Node *root) {
    if(!root) return ;
    inorder(root->left);
    cout << root->data << endl;
    inorder(root->right);
}

int main()
{
    Node* root=NULL;
    root=insert(root,10);
    root=insert(root,20);
    root=insert(root,30);
    root=insert(root,50);
    root=insert(root,70);
    root=insert(root,5);
    root=insert(root,100);
    root=insert(root,95);

    inorder(root);





}