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
    int len(ListNode *head)
    {
        int i=0;
        while(head!=NULL)
        {
            i++;
            head=head->next;
        }
        return i;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;
        int n=len(head);
        k=k%n;
        k=n-k;
        if(k==n || k==0) return head;
        int h=k;
        ListNode *temp=head, *prev;
        while(h>0)
        {
            prev=temp;
            temp=temp->next;
            h--;
        }
        prev->next=NULL;
        ListNode *l1=head, *l2=temp;
        ListNode *t=l2;
        while(t->next!=NULL)
            t=t->next;
        t->next=l1;
        return l2;
    }
};









