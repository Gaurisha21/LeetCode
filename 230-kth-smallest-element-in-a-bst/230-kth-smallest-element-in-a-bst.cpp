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
    TreeNode *rightMost(TreeNode* l, TreeNode* curr)
    {
        while(l->right!=NULL and l->right!=curr)
            l=l->right;
        return l;
    }
    int kthSmallest(TreeNode* root, int k) {
        TreeNode *curr=root;
        int flag = 0;
        while(curr!=NULL)
        {
            if(curr->left==NULL)
            {
                if(--k==0)
                    flag = curr->val;
                curr=curr->right;
            }
            else
            {
                TreeNode *rm=rightMost(curr->left, curr);
                if(rm->right==NULL)
                {
                    rm->right=curr;
                    curr=curr->left;
                }
                else
                {
                    rm->right=NULL;
                    if(--k==0)
                    flag = curr->val;
                    curr=curr->right;
                }
            }
        }
        return flag;
    }
};