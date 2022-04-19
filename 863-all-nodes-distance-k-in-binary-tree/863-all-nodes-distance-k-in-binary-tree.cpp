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
    vector<TreeNode*> nodeToRootPath(TreeNode* root, TreeNode* target)
    {
        if(root==NULL) return {};
        if(root==target)
            return {root};
        vector<TreeNode*> l = nodeToRootPath(root->left, target);
        if(l.size()!=0)
        {
            l.push_back(root);
            return l;
        }
        vector<TreeNode*> r = nodeToRootPath(root->right, target);
        if(r.size()!=0)
        {
            r.push_back(root);
            return r;
        }
        return {};    
    }
    void nodesK(TreeNode* root, int k, vector<int> &ans)
    {
        if(root==NULL)
            return;
        if(k==0)
        {
            ans.push_back(root->val);
            return;
        }
        if(root->left!=NULL and root->left->val>=0)
            nodesK(root->left,k-1,ans);
        if(root->right!=NULL and root->right->val>=0)
            nodesK(root->right,k-1,ans);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<TreeNode*> path = nodeToRootPath(root,target);
        int n=path.size();
        vector<int> ans;
        for(int i=0; i<n; i++)
        {
            int K=k-i;
            if(i!=0)
                path[i-1]->val=-path[i-1]->val;
            nodesK(path[i],K,ans);
            if(i!=0)
                path[i-1]->val=-path[i-1]->val;
        }
        return ans;
    }
};









