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
    int search(vector<int> inorder, int curr, int start, int end)
    {
        for(int i=start; i<=end; i++)
        {
            if(curr==inorder[i])
                return i;
        }
        return -1;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int start, int end, vector<int> &idx)
    {
        int i=idx[0];
        if(start>end)
            return NULL;
        int curr=postorder[i];
        idx[0]--;
        TreeNode *root=new TreeNode(curr);
        if(start==end)
            return root;
        int pos=search(inorder, curr, start, end);
        root->right=buildTree(inorder, postorder, pos+1, end, idx);
        root->left=buildTree(inorder, postorder, start, pos-1, idx);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        vector<int> idx;
        int n=inorder.size()-1;
        idx.push_back(n);
        return buildTree(inorder, postorder, 0, n, idx);
    }
};