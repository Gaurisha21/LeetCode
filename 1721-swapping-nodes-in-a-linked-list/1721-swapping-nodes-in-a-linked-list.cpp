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
    ListNode* lastKnode(ListNode *head, int k)
    {
        ListNode *f=head, *s=head, *pb;
        while(k--)
            f=f->next;
        while(f!=NULL)
        {
            pb=s;
            s=s->next;
            f=f->next;
        }
        // cout<<s->val<<endl;
        return s;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        int n=len(head);
        int l=k;
        k--;
        ListNode *f=head, *b, *temp=head;
        while(k--)
        {
            temp=temp->next;
            f=temp;
        }
        b= lastKnode(head,l);
        // cout<<f->val<<" "<<b->val;
        swap(b->val,f->val);
        return head;
    }
};






















