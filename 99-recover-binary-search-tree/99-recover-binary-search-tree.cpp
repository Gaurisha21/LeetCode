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
    void inorder(TreeNode *root, vector<int> &ans)
    {
        if(root==NULL)
            return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    void insertRight(TreeNode *root, stack<TreeNode*>&st)
    {
        while(root!=NULL)
        {
            st.push(root);
            root=root->left;
        }
    }
    void recoverTree(TreeNode* root) {
        vector<int> ans;
        inorder(root,ans);
        sort(ans.begin(), ans.end());
        stack<TreeNode*> st;
        insertRight(root,st);
        int i=0;
        while(!st.empty())
        {
            TreeNode *node=st.top();
            st.pop();
            node->val=ans[i++];
            insertRight(node->right,st);
        }
    }
};








