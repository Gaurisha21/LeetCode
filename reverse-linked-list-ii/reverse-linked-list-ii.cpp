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
    ListNode *tt = NULL;
    ListNode *th = NULL;
    void add(ListNode *curr)
    {
        if(th == NULL ) th = tt = curr;
        else{
            curr->next = th;
            th = curr;
        }
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int idx = 1;
        ListNode* curr = head, *prev, *forw;
        if(left>1)
        {
            while(idx<left)
            {
                prev = curr;
                curr= curr->next;
                idx++;
            }
            prev->next = NULL;
        }
        while(idx<=right)
        {
            forw = curr->next;
            curr->next = NULL;
            add(curr);
            curr = forw;
            idx++;
        }
        left==1 ? prev = th : prev->next = th;
        tt->next = forw;
        return left == 1 ? prev : head;
    }
};