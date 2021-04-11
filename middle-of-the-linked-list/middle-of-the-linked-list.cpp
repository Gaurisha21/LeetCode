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
    ListNode* middleNode(ListNode* head) {
        ListNode * f=head, *s=head, *temp=head;
        while(f!=NULL and f->next !=NULL)
        {
            f=f->next->next;
            s=s->next;
        }
        /*int n=0;
        while(temp!=NULL)
        {
            n++;
            temp = temp->next;
        }
        if(n%2!=0)
            return s;
        return s->next;*/
        return s;
    }
};