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
    void inOrder(TreeNode*root, vector<long> &ans)
    {
        if(root == NULL) return;
        inOrder(root->left, ans);        
        ans.push_back(root->val);
        inOrder(root->right, ans);
    }
    bool isValidBST(TreeNode* root) {
        vector<long> ans;
        inOrder(root, ans);
        for(long i=1; i<ans.size(); i++)
        {
            if(ans[i]<=ans[i-1]) return false;
        }
        return true;
    }
};