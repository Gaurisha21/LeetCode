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
    TreeNode *rightMost(TreeNode *node, TreeNode* curr)
    {
        while(node->right!=NULL and node->right!=curr)
            node=node->right;
        return node;
    }
    void flatten(TreeNode* root) {
        TreeNode *curr=root;
        while(curr!=NULL)
        {
            if(curr->left==NULL)
                curr=curr->right;
            else
            {
                TreeNode *rm=rightMost(curr->left, curr);
                if(rm->right==NULL)
                {
                    rm->right=curr->right;
                    curr->right=curr->left;
                    curr->left=NULL;
                    curr=curr->right;
                }
            }
        }
    }
};