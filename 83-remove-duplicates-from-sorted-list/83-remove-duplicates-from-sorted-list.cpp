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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL) return head; 
        ListNode *prev=new ListNode(-1), *q=head, *t=head->next;
        prev->next=head;
        while(t!=NULL)
        {
            if(t->val==q->val)
                q->next=t->next;
            else
                q=q->next;
            t=t->next;
        }
        return prev->next;
    }
};