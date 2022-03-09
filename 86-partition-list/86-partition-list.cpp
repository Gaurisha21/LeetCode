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
        ListNode *less=new ListNode(-1), *more=new ListNode(-1), *l=less, *m=more, *temp=head;
        while(temp!=NULL)
        {
            if(temp->val<x)
            {
                l->next=temp;
                l=l->next;
            }
            else
            {
                m->next=temp;
                m=m->next;
            }
            temp=temp->next;
        }
        l->next=more->next;
        m->next=NULL;
        return less->next;
    }
};