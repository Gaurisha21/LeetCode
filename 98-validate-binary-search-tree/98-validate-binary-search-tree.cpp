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
    bool isValidBST(TreeNode* root) {
        TreeNode *curr=root;
        long long prev = -(long long)1e14;
        bool flag = true;
        while(curr!=NULL)
        {
            if(curr->left==NULL)
            {
                if(prev>=curr->val)
                    flag = false;
                cout<<curr->val<<" ";
                prev=curr->val;
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
                    if(prev>=curr->val)
                        flag = false;
                    cout<<curr->val<<" ";
                    prev=curr->val;
                    curr=curr->right;
                }
            }
        }
        return flag;
    }
};









