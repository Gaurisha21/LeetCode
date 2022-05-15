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
    void hasPathSum(TreeNode* root, int targetSum, bool &ans, int sum)
    {
        if(root==NULL)
            return;
        if(root->left==NULL and root->right==NULL)
        {
            if(sum+root->val==targetSum)
                ans=true;
            return;
        }
        sum+=root->val;
        hasPathSum(root->left,targetSum,ans,sum);
        hasPathSum(root->right,targetSum,ans,sum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool ans=false;
        hasPathSum(root,targetSum,ans,0);
        return ans;
    }
};