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
        ListNode *temp=head, *p=new ListNode(-1), *curr=p;
        p->next=head;
        while(temp!=NULL and temp->next!=NULL)
        {
            if(temp->next->val==temp->val)
            {
                while(temp->next!=NULL and temp!=NULL and temp->next->val==temp->val)
                    temp=temp->next;
                if(temp->next==NULL)
                {
                    curr->next=NULL;
                    break;
                }
                else
                {
                    temp=temp->next;
                    curr->next=temp;
                }
            }
            if(temp!=NULL and temp->next!=NULL and temp->val!=temp->next->val)
            {
                curr->next=temp;
                curr=temp;
                temp=temp->next;
            }
        }
        return p->next;
    }
};