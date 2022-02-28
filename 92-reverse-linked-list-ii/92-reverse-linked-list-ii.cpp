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
    ListNode *th=NULL, *tt=NULL;
    void addFirst(ListNode *curr)
    {
        if(th==NULL)
            th=tt=curr;
        else
        {
            curr->next=th;
            th=curr;
        }
    }
    ListNode* reverseBetween(ListNode* head, int l, int r) {
        int k=r-l+1;
        int L=l;
        ListNode *left=head, *right=head, *oh;
        while(l>1)
        {
            oh=left;
            left=left->next;
            l--;
        }
        ListNode *curr=left, *forw;
        while(k--)
        {
            forw=curr->next;
            curr->next=NULL;
            addFirst(curr);
            curr=forw;
        }
        if(L>1) oh->next=th;
        tt->next=forw;
        return L==1 ? th : head;
    }
};