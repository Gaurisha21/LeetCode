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
    int minVal(TreeNode *root)
    {
        while(root->left!=NULL)
            root=root->left;
        return root->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)
            return NULL;
        if(root->val>key)
            root->left = deleteNode(root->left, key);
        else if(root->val<key)
            root->right = deleteNode(root->right, key);
        else
        {
            if(root->left==NULL || root->right==NULL)
                return root->left==NULL ? root->right : root->left;
            else
            {
                int minEle = minVal(root->right);
                root->val = minEle;
                root->right = deleteNode(root->right, minEle);
            }
        }
        return root;
    }
};