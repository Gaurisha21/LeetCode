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
    bool node2root(TreeNode *root, int target, vector<TreeNode*> &ans)
    {
        if(root==NULL) return false;
        if(root->val == target)
        {
            ans.push_back(root);
            return true;
        }
        bool res = node2root(root->left, target, ans) || node2root(root->right, target, ans);
        if(res) ans.push_back(root);
        return res;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> ansP;
        vector<TreeNode*> ansQ;
        bool P = node2root(root, p->val, ansP);
        bool Q = node2root(root, q->val, ansQ);
        int pi = ansP.size()-1, qi = ansQ.size()-1;
        TreeNode* LCA = NULL;
        while(pi>=0 && qi>=0)
        {
            if(ansP[pi] != ansQ[qi]) break;
            LCA = ansP[pi];
            pi--;
            qi--;            
        }
        return LCA;
    }
};





















