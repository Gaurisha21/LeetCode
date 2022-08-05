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
    void insertLeft(TreeNode* node, stack<TreeNode*> &st)
    {
        while(node!=NULL)
        {
            st.push(node);
            node=node->left;
        }
    }
    int sum(TreeNode *root)
    {
        int totSum=0;
        stack<TreeNode*> st;
        insertLeft(root,st);
        while(!st.empty())
        {
            TreeNode *node = st.top();
            st.pop();
            totSum+=node->val;
            insertLeft(node->right,st);
        }
        return totSum;
    }
    TreeNode* bstToGst(TreeNode* root) {
        int totSum=sum(root);
        
        stack<TreeNode*> st;
        insertLeft(root,st);
        while(!st.empty())
        {
            TreeNode *node = st.top();
            st.pop();
            int prevNodeVal=node->val;
            node->val=totSum;
            totSum-=prevNodeVal;
            insertLeft(node->right,st);
        }
        return root;
    }
};