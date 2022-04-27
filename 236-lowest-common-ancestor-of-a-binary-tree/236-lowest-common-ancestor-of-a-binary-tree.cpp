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
    vector<TreeNode *> nodeToRoot(TreeNode *root, TreeNode *target)//, vector<int> &path)
    {
        if(root==NULL)
            return {};
        if(root==target)
            return {root};
        vector<TreeNode *> l, r;
        l=nodeToRoot(root->left,target);
        if(l.size()!=0)
        {
            l.push_back(root);
            return l;
        }
        r=nodeToRoot(root->right,target);
        if(r.size()!=0)
        {
            r.push_back(root);
            return r;
        }
        return {};
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode *> ppath, qpath;
        ppath = nodeToRoot(root, p);
        qpath = nodeToRoot(root,q);
        TreeNode * LCA;
        int i=ppath.size()-1, j=qpath.size()-1;
        while(i>=0 and j>=0)
        {
            if(ppath[i]!=qpath[j])
                break;
            LCA = ppath[i];
            i--;
            j--;
        }
        return LCA;
    }
};