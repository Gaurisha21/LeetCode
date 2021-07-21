/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *LCANode = nullptr;
    bool LCA(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr)
            return false;
        bool selfPresent = (root == p || root == q);

        bool leftPresent = LCA(root->left, p, q);
        bool rightPresent = LCA(root->right, p, q);
        
        if ((leftPresent && rightPresent) || (leftPresent && selfPresent) || (rightPresent && selfPresent))
            LCANode = root;

        return leftPresent || rightPresent || selfPresent;
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        LCA(root, p, q);
        return LCANode;
    }

};