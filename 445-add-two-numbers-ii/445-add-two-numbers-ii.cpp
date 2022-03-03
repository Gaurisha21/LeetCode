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
    ListNode* reverse(ListNode* head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode*prev = NULL, *curr= head,  *nex;
        while(curr!=NULL)
        {
            nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL || l2==NULL) return l1==NULL ? l2 : l1;
        l1 = reverse(l1);
        l2=reverse(l2);
        ListNode *dummy = new ListNode(-1), *prev = dummy, *c1 = l1, *c2 = l2;
        int carry = 0;
        while(c1 != NULL || c2 != NULL || carry != 0)
        {
            int sum = carry + (c1!=NULL ? c1->val : 0) + (c2!=NULL ? c2->val : 0);
            carry = sum/10;
            prev->next = new ListNode(sum%10);
            prev = prev->next;
            if(c1!=NULL) c1=c1->next;
            if(c2!=NULL) c2=c2->next;
        }
        return reverse(dummy->next); 
    }
};