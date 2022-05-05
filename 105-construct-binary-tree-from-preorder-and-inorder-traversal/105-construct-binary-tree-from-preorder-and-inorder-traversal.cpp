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
    int idx=0;
    int search(int curr, vector<int> inorder, int start, int end)
    {
        for(int i=start; i<=end; i++)
        {
            if(curr==inorder[i])
                return i;
        }
        return -1;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int start, int end)
    {
        if(start>end)
            return NULL;
        int curr=preorder[idx];
        idx++;
        TreeNode *node= new TreeNode(curr);
        int pos = search(curr, inorder, start, end);
        if(start==end)
            return node;
        node->left=buildTree(preorder, inorder, start, pos-1);
        node->right=buildTree(preorder, inorder, pos+1, end);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size()-1;
        return buildTree(preorder, inorder, 0, n);
    }
};