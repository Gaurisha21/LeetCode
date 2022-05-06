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
    int searchPos(vector<int> postorder, int curr, int start, int end)
    {
        for(int i=start; i<=end; i++)
        {
            if(curr==postorder[i])
                return i;
        }
        return -1;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder, int start, int end, vector<int> &idx)
    {
        if(start>end)
            return NULL;
        int curr=preorder[idx[0]];
        idx[0]++;
        TreeNode *root=new TreeNode(curr);
        if(start==end)
            return root;
        int pos = searchPos(postorder, preorder[idx[0]], start, end);
        root->left=constructFromPrePost(preorder, postorder, start, pos, idx);
        root->right=constructFromPrePost(preorder, postorder, pos+1, end-1, idx);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n=preorder.size()-1;
        vector<int> idx(1,0);
        return constructFromPrePost(preorder, postorder, 0, n, idx);
    }
};