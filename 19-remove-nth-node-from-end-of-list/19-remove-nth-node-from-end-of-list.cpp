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
    ListNode* removeNthFromEnd(ListNode* head, int k) {
        ListNode *s=head, *f=head, *p=new ListNode(-1), *prev=p;
        p->next=head;
        while(k>0)
        {
            k--;
            f=f->next;
        }
        while(f!=NULL)
        {
            prev=s;
            s=s->next;
            f=f->next;
        }
        prev->next=s->next;
        s->next=NULL;
        delete(s);
        return p->next;
    }
};