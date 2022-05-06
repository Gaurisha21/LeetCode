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
    void burnTree(TreeNode *root, TreeNode *block, int time, vector<vector<int>> &ans)
    {
        if(root==NULL || root==block)
            return;
        if(time==ans.size())
            ans.push_back({});
        ans[time].push_back(root->val);
        burnTree(root->left, block, time+1, ans);
        burnTree(root->right, block, time+1, ans);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        burnTree(root, NULL, 0, ans);
        int s=0, e=ans.size()-1;
        while(s<=e)
            swap(ans[s++],ans[e--]);
        return ans;
    }
};