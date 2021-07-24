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
    ListNode *Prev;
    ListNode *middle(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        Prev = NULL;
        ListNode *fast = head, *slow = head;
        while(fast->next!=NULL and fast->next->next!=NULL)
        {
            fast = fast->next->next;
            Prev = slow;
            slow = slow->next;
        }
        return slow;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr)
            return NULL;
        if(head->next == nullptr)
        {
            TreeNode *treenode = new TreeNode(head->val);
            return treenode;
        }
        ListNode *mid = middle(head), *prev = Prev, *forw = mid->next;
        TreeNode *root = new TreeNode(mid->val);
        mid->next = NULL;
        if(prev!=NULL) prev->next = NULL;
        ListNode *leftHead = (prev != nullptr ? head : nullptr), *rightHead = forw;
        root->left = sortedListToBST(leftHead);
        root->right = sortedListToBST(rightHead);
        return root;
    }
};


















