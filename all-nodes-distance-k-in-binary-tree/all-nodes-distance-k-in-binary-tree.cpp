/*res
    path.push_back(**
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
    bool node2root(TreeNode *root, int target, vector<TreeNode*> &path)
    {
        if(root==NULL) return false;
        if(root->val == target){
            path.push_back(root);
            return true;
        }
        bool res = node2root(root->right,target,path) || node2root(root->left,target,path);
        if(res)
            path.push_back(root);
        return res;
    }
    
    void knode(TreeNode *root, int k, TreeNode *block, vector<int> &ans){
        if(root==NULL || k<0 || root == block) return;
        if(k==0)
        {
            ans.push_back(root->val);
            return;
        }
        knode(root->left, k-1, block, ans);
        knode(root->right, k-1, block, ans);
    }
        
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<TreeNode*> path;
        vector<int> ans;
        bool res = node2root(root, target->val, path);
        TreeNode *block=NULL;
        for(int i=0;i<path.size(); i++)
        {
            knode(path[i], k-i, block, ans);
            block  = path[i];
        }
        return ans;
    }
};