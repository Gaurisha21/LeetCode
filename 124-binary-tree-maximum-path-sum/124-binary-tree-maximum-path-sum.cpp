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
    int solve(TreeNode* root, int &ans)
    {
        if(root==NULL)
            return 0;
        
        int lv = solve(root->left,ans);
        int rv = solve(root->right,ans);
        
        int x = max(max(root->val,root->val+lv+rv), max(root->val+rv,root->val+lv));
        ans = max(ans,x);
        return max(root->val,max(root->val+lv,root->val+rv));
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        solve(root,ans);
        return ans;
    }
};