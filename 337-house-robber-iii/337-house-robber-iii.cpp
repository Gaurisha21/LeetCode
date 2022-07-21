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
    vector<int> robHouse(TreeNode *root)
    {
        if(root==NULL)
            return {0,0};
        if(root->left==NULL and root->right==NULL)
            return {root->val,0};
        
        vector<int> leftAns = robHouse(root->left);
        vector<int> rightAns = robHouse(root->right);
        
        int withRob = leftAns[1]+rightAns[1]+root->val;
        int withoutRob = max(leftAns[0],leftAns[1])+max(rightAns[0],rightAns[1]);
        
        return {withRob, withoutRob};
    }
    int rob(TreeNode* root) {
        vector<int> ans = robHouse(root);
        return max(ans[0],ans[1]);
    }
};