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
    ListNode *tt=NULL, *th=NULL;
    int length(ListNode *head)
    {
        int i=0;
        while(head!=NULL)
        {
            i++;
            head=head->next;
        }
        return i;
    }
    void addFirst(ListNode *curr)
    {
        if(th==NULL)
        {
            th=curr;
            tt=curr;
        }
        else
        {
            curr->next=th;
            th=curr;
        }
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k <= 1)
            return head;
        int len=length(head);
        ListNode *curr=head, *oh=NULL, *ot=NULL;
        while(curr!=NULL and len>=k)
        {
            int tempK=k;
            while(tempK-->0)
            {
                ListNode *forw=curr->next;
                curr->next=NULL;
                addFirst(curr);
                curr=forw;
            }
            if(oh==NULL)
            {
                oh=th;
                ot=tt;
            }
            else
            {
                ot->next=th;
                ot=tt;
            }
            th=NULL;
            tt=NULL;
            len-=k;
        }
        ot->next=curr;
        return oh;
    }
};











