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
        ListNode *curr=head, *forw=head->next;
        while(forw!=NULL) 
        {
            if(curr->val==forw->val) curr->next=forw->next;
            else curr=curr->next;
            forw=forw->next;
        }
        return head;
    }
};