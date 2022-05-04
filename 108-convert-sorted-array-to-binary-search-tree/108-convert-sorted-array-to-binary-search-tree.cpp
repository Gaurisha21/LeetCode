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
    TreeNode* sortedArrayToBST(vector<int>& nums, int s, int e)
    {
        if(s>e)
            return NULL;
        int m=s+((e-s)/2);
        TreeNode *root=new TreeNode(nums[m]);
        root->left=sortedArrayToBST(nums,s,m-1);
        root->right=sortedArrayToBST(nums,m+1,e);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size()-1;
        return sortedArrayToBST(nums,0,n);
    }
};