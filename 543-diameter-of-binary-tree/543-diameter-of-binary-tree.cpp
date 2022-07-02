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
    // {height, diameter}
    vector<int> diameter(TreeNode* root) 
    {
        if(root==NULL)
        {
            vector<int> base = {-1,0};
            return base;
        }
        
        vector<int> ls = diameter(root->left);
        vector<int> rs = diameter(root->right);
        
        vector<int> curr(2);
        curr[0] = max(ls[0],rs[0])+1;
        curr[1] = max(max(ls[1],rs[1]), ls[0]+rs[0]+2);
        return curr;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        vector<int> ans = diameter(root);
        return ans[1];
    }
};