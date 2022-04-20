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
    ListNode* partition(ListNode* head, int x) {
        ListNode *less = new ListNode(-1);
        ListNode *more = new ListNode(-1);
        ListNode *l=less, *m=more, *p=head;
        while(p!=NULL)
        {
            if(p->val<x)
            {
                l->next=p;
                l=l->next;
                p=p->next;
            }
            else
            {
                m->next=p;
                m=m->next;
                p=p->next;
            }
        }
        l->next = more->next;
        m->next=NULL;
        return less->next;
    }
};