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
    void kdown(TreeNode* node, TreeNode* block, int k, vector<int>&ans)
    {
        if(node==NULL || k<0 || node==block)
            return;
        if(k==0)
        {
            ans.push_back(node->val);
            return;
        }
        kdown(node->left, block, k-1, ans);
        kdown(node->right, block, k-1, ans);
    }
    int distanceK(TreeNode* root, TreeNode* target, int k, vector<int>&ans)
    {
        if(root==NULL)
            return -1;
        if(root==target)
        {
            kdown(root,NULL,k,ans);
            return 1;
        }
        int ld = distanceK(root->left,target,k,ans);
        if(ld!=-1)
        {
            kdown(root,root->left,k-ld,ans);
            return ld+1;
        }
        int rd = distanceK(root->right,target,k,ans);
        if(rd!=-1)
        {
            kdown(root,root->right,k-rd,ans);
            return rd+1;
        }
        return -1;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        int x = distanceK(root, target, k, ans);
        return ans;
    }
};