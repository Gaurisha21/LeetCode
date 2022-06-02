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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> midNode(ListNode *head)
    {
        if(head==NULL || head->next==NULL)
        return {NULL,head};
        ListNode *s=head, *f=head, *p;
        while(f!=NULL and f->next!=NULL)
        {
            p=s;
            s=s->next;
            f=f->next->next;
        }
        return {p,s};
    }

    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL)
            return NULL;
        // if(head->next==NULL)
        // {
        //     return new TreeNode(head->val);
        // }
        vector<ListNode*> arr = midNode(head);
        ListNode *mid=arr[1];
        // cout<<mid->val<<endl;
        ListNode *p=arr[0], *f=mid->next;
        if(p!=NULL)
            p->next=NULL;
        mid->next=NULL;
        ListNode *leftHead=(p!=NULL ? head : NULL);
        TreeNode *root = new TreeNode(mid->val);
        root->left=sortedListToBST(leftHead);
        root->right=sortedListToBST(f);
        return root;
    }
};