/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *f=head, *s=head;
        while(f!=NULL and f->next!=NULL)
        {
            f=f->next->next;
            s=s->next;
            if(s==f)
                return true;
        }
        return false;
    }
};