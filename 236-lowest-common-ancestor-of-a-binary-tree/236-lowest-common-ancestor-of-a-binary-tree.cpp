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
    TreeNode *node=NULL;
    bool LCA(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root==NULL)
            return false;
        bool self = (root==p||root==q);
        bool Left = LCA(root->left,p,q);
        bool Right = LCA(root->right,p,q);
        if((self && Left)||(self && Right)||(Left && Right))
            node=root;
        return (self||Left||Right);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        LCA(root,p,q);
        return node;
    }
}; 