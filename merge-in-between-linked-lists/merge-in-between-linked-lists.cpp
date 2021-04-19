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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *A=list1, *B=list1, *tail=list2;
        while(a-->1)
        {
            A=A->next;
        }
        while(b-->=1)
        {
            B=B->next;
        }
        A->next=list2;
        while(tail->next!=NULL)
        {
            tail=tail->next;
        }
        tail->next=B->next;
        //cout<<tail->val;
        //cout<<A->val<<" "<<B->val;
        return list1;
    }
};