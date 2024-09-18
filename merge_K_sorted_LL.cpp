//class compare we build for min heap
class Compare {
public:
    bool operator()(Node* a,Node *b) {
        return a->data>b->data;
    }
};
class Solution {
public:
    // Function to merge K sorted linked list.
    Node* mergeKLists(vector<Node*>& arr) {
        // Your code here
        int k=arr.size();
        priority_queue<Node*, vector<Node *>,Compare>pq(arr.begin(),arr.end());
        Node *root=new Node(0);
        Node *tail=root;
        Node *temp;
        while(!pq.empty()) {
            temp=pq.top();
            pq.pop();
            tail->next=temp;
            tail=tail->next;
            if(temp->next)
                pq.push(temp->next);

        }
        return root->next;
    }
};



