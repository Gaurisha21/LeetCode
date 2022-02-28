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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *c1=l1, *c2=l2, *p=new ListNode(-1), *dum=p;
        while(c1!=NULL and c2!=NULL)
        {
            if(c1->val<=c2->val)
            {
                p->next = c1;
                c1=c1->next;
            }
            else
            {
                p->next = c2;
                c2=c2->next;
            }
            p=p->next;
        }
        p->next = c1!=NULL ? c1 : c2;
        return dum->next;
    }
    ListNode * mid(ListNode *head)
    {
        ListNode *s=head, *f=head;
        while(f->next!=NULL and f->next->next!=NULL)
        {
            s=s->next;
            f=f->next->next;
        }
        return s;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode *midd = mid(head);
        ListNode *l2 = midd->next;
        midd->next=NULL;
        return mergeTwoLists(sortList(head), sortList(l2));
    }
};