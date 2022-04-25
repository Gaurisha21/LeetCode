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
    void sum(TreeNode *root, int &s, int low, int high)
    {
        if(root==NULL) return;
        if(root->val>=low and root->val<=high)
            s+=root->val;
        sum(root->left,s,low,high);
        sum(root->right,s,low,high);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int s=0;
        sum(root,s,low,high);
        return s;
    }
};