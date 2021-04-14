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
    int len(ListNode* l)
    {
        int count=0;
        while(l!=NULL)
        {
            count++;
            l=l->next;
        }
        return count;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA or !headB) return NULL;
        int la=len(headA);
        int lb=len(headB);
        //cout<<"a "<<la<<" b "<<lb<<endl;
        if(la>lb)
        {
            int d=la-lb;
            while(d--)
            {
                headA=headA->next;
            }
            //cout<<d<<" dd "<<headA->val<<endl;
            while(headA!=headB)
            {
                headA=headA->next;
                headB=headB->next;
            }
            //cout<<headA->val<<headB->val<<endl;
            return headA;
        }
        else
        {
            int d=lb-la;
            while(d--)
            {
                headB=headB->next;
            }
            //cout<<d<<" jj "<<headB->val<<endl;
            while(headA!=headB)
            {
                headA=headA->next;
                headB=headB->next;
            }
            //cout<<headA->val<<headB->val<<endl;
            return headB;
        }
        return NULL;
    }
};
















