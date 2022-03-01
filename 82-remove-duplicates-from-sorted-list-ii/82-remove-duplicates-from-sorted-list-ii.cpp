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
        ListNode *p=new ListNode(-1), *q=p, *temp=head;
        p->next=head;
        while(temp!=NULL and temp->next!=NULL)
        {
            // cout<<q->val<<" ";
            if(temp->val==temp->next->val )
            {
                while(temp!=NULL and temp->next!=NULL and temp->val==temp->next->val)
                    temp=temp->next;
                if(temp!=NULL)
                {
                    temp=temp->next;
                    q->next=temp;
                }
                else 
                {
                    q->next=NULL;
                    break;
                }
                
            }
            if(temp!=NULL and temp->next!=NULL and temp->val!=temp->next->val)
            {
                q->next=temp;
                q=temp;
                temp=temp->next;
            }
        }
        return p->next;
    }
};