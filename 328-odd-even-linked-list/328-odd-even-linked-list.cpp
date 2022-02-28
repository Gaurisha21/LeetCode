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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode *c1=head, *c2=head->next, *h1=c1, *h2=c2;
        while(c2!=NULL and c2->next!=NULL)
        {
            ListNode *f=c2->next;
            c1->next=f;
            c2->next=f->next;
            c1=c1->next;
            c2=c2->next;
        }
        c1->next=h2;
        return h1;
    }
};