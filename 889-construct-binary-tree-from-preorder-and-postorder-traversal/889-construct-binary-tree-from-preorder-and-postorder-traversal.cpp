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
    int i=0;
    int search(vector<int> postorder, int start, int end, int curr)
    {
        for(int j=start; j<=end; j++)
        {
            if(postorder[j]==curr)
                return j;
        }
        return -1;
    }
    TreeNode* build(vector<int> preorder, vector<int> postorder, int start, int end)
    {
        if(start>end)
            return NULL;
        int curr=preorder[i++];
        TreeNode* node = new TreeNode(curr);
        if(start==end)
            return node;
        int pos = search(postorder, start, end, preorder[i]);
        node->left = build(preorder, postorder, start, pos);
        node->right = build(preorder, postorder, pos+1, end-1);
        return node;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n=preorder.size()-1;
        return build(preorder, postorder, 0, n);
    }
};