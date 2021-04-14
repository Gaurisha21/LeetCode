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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *temp=head, *p=new ListNode();
        p->next=head;
        ListNode *q=p;
        while(temp!=NULL)
        {
            if(temp->val==val)
                q->next = temp->next;
            else
                q=q->next;
            temp=temp->next;
        }
        return p->next;
    }
};