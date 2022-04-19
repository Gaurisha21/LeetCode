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
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root==NULL) return {};
       if(root->left==NULL and root->right==NULL)
           return {to_string(root->val)};
        vector<string> ans;
        vector<string> lans= binaryTreePaths(root->left);
        for(string s : lans)
        {
            s = to_string(root->val)+"->"+s;
            ans.push_back(s);
        }
        vector<string> rans = binaryTreePaths(root->right);
        for(string s : rans)
        {
            s = to_string(root->val)+"->"+s;
            ans.push_back(s);
        }
        return ans;        
    }
};