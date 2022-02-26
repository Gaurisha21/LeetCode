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
    ListNode* reverse(ListNode *head)
    {
        ListNode *curr=head, *prev=NULL;
        while(curr!=NULL)
        {
            ListNode *forw=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forw;
        }
        return prev;
    }
    ListNode *mid(ListNode *head)
    {
        ListNode *s=head, *f=head;
        while(f->next!=NULL and f->next->next!=NULL)
        {
            f=f->next->next;
            s=s->next;
        }
        return s;
    }
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL) return true;
        ListNode *l1=head, *midd, *l2;
        midd=mid(head);
        // cout<<midd->val;
        l2=midd->next; 
        l2=reverse(l2);
        // cout<<l2->val;
        midd->next=NULL;
        while(l1!=NULL and l2!=NULL)
        {
            if(l1->val!=l2->val) return false;
            l1=l1->next;
            l2=l2->next;
        }
        return true;
    }
};