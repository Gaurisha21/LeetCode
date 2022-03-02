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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL || l2==NULL) return l1==NULL ? l2 : l1;
        ListNode *c1=l1, *c2=l2, *head=new ListNode(-1), *Head=head;
        int carry=0;
        while(c1!=NULL || c2!=NULL || carry!=0)
        {
            int sum = (c1!=NULL?c1->val:0)+(c2!=NULL?c2->val:0)+carry;
            carry=sum/10;
            head->next=new ListNode(sum%10);
            head=head->next;
            if(c1!=NULL)c1=c1->next;
            if(c2!=NULL)c2=c2->next;
        }
        return Head->next;
    }
};












