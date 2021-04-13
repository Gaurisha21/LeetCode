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
    ListNode* swapNodes(ListNode* head, int k) {
        int f=0;
        ListNode *temp = head, *slow=head, *t=head, *fast;
        while(t!=NULL)
        {
            t=t->next;
            f++;
        }
        //cout<<f<<endl;
        if(f==1) return head;
        while(k>1)
        {
            temp=temp->next;
            k--;
        }
        //cout<<temp->val<<endl;
        fast = temp;
        while(fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
        //cout<<fast->val<<slow->val<<temp->val;
        swap(temp->val,slow->val);
        return head;
    }
};