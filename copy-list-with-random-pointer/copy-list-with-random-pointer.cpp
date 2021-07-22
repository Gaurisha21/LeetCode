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
        Node* temp = head, *head2 = new Node(-1), *prev = head2;
        unordered_map<Node*, Node*> m;
        while(temp!=NULL){
            prev->next = new Node(temp->val);
            m[temp] = prev->next;
            prev= prev->next;
            temp=temp->next;
        }  
        head2=head2->next;
        Node *curr = head;
        Node *copy = head2;
        while(curr != NULL)
        {
            copy = m[curr];
            copy->random = curr->random!=NULL ? m[curr->random] : NULL;
            curr = curr->next;
            copy=copy->next;
        }
        return head2;
        
    }
};