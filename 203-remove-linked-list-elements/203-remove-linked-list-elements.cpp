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
        ListNode *temp=head, *prev=new ListNode(-1), *q=prev;
        prev->next=temp;
        q=prev;
        while(temp!=NULL)
        {
            if(temp->val==val)
                q->next=temp->next;
            else
                q=q->next;
            temp=temp->next;
        }
        return prev->next;
    }
};