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
    vector<TreeNode*> generateTrees(int start, int end)
    {
        if(start>end)
            return {NULL};
        vector<TreeNode*> ans;
        for(int i=start; i<=end; i++)
        {
            vector<TreeNode*> leftAns = generateTrees(start, i-1);
            vector<TreeNode*> rightAns = generateTrees(i+1, end);
            for (TreeNode* left: leftAns) {
                for (TreeNode* right: rightAns) {
                    TreeNode *root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        return generateTrees(1,n);
    }
};