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
        unordered_map<Node*, Node*> map;
        Node *temp=head, *head2=new Node(-1), *h2=head2;
        while(temp!=NULL)
        {
            h2->next=new Node(temp->val);
            h2=h2->next;
            map[temp]=h2;
            temp=temp->next;
        }
        // for (auto i = map.begin(); i != map.end(); i++)
        //     cout<<i->first<<" "<<i->second<<endl;
        temp=head;
        Node *t=head2->next;
        while(temp!=NULL)
        {
            t->random = temp->random!=NULL ? map[temp->random] : NULL;
            temp=temp->next;
            t=t->next;
        }
        return head2->next;
    }
};