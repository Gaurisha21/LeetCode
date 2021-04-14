/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void inserth(ListNode* &head, int data)
    {
        if(!head)
        {
            head = new ListNode(data);
            return;
        }
        ListNode* n = new ListNode(data);
        n->next = head;
        head = n;
        return;
    }
    void insertEnd(ListNode* &head, int val)
    {
        ListNode* n = new ListNode(val);
        if(head == NULL)
        {
            inserth(head, val);
            return;
        }
        ListNode* temp = head;
        while(temp -> next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
    }
    ListNode* oddEvenList(ListNode* head) {
        ListNode *o=NULL, *e=NULL;
        for(int i=0; head!=NULL; i++)
        {
            if(i%2==0)
                insertEnd(o,head->val);
            else
                insertEnd(e,head->val);
            head=head->next;
        }
        //cout<<e->val<<" o "<<o->val<<endl;
        if(o==NULL)
            o=e;
        else
        {
            ListNode *temp=o;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=e;
        }
        return o;
    }
};