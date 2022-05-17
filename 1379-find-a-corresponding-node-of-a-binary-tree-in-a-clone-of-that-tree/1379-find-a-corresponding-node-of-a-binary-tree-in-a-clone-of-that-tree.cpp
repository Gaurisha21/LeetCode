/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void insertLeft(TreeNode* node, stack<TreeNode*>&st)
    {
        while(node!=NULL)
        {
            st.push(node);
            node=node->left;
        }
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode *curr=cloned;
        stack<TreeNode*> st;
        insertLeft(curr,st);
        while(!st.empty())
        {
            TreeNode *node=st.top();
            st.pop();
            if(node->val==target->val)
                return node;
            insertLeft(node->right, st);
        }
        return NULL;
    }
};