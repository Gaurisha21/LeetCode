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
    TreeNode* rightMost(TreeNode*root, TreeNode* curr)
    {
        while(root->right!=NULL and root->right!=curr)
            root = root->right;
        return root;
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int rv = -1;
        TreeNode *curr = root;
        while(curr!=NULL){
            TreeNode *Left = curr->left;
            if(Left == NULL){
                if(--k == 0) rv = curr->val;
                curr= curr->right;
            }
            else{
                TreeNode *Right = rightMost(Left, curr);
                if(Right->right==NULL)
                {
                    Right->right = curr;
                    curr = curr->left;
                }
                else
                {
                    Right->right = NULL;
                    if(--k == 0) rv = curr->val;
                    curr = curr->right;
                }
            }
        } 
        return rv;
    }
};