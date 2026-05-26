/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*> mpp;
        Node* curr = head;
        while(curr){
            mpp[curr] = new Node(curr->val);
            curr = curr->next;
        }
        Node* temp = head;
        while(temp){
            Node* nd = mpp[temp];
            nd->next = mpp[temp->next];
            nd->random = mpp[temp->random];
            temp = temp->next;
        }
        return mpp[head];
    }
};
