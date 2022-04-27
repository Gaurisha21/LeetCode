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
    void reverse(vector<TreeNode *> &path)
    {
        int i=0, j=path.size()-1;
        while(i<=j)
            swap(path[i++],path[j--]);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode *> ppath, qpath;
        ppath = nodeToRoot(root, p);
        qpath = nodeToRoot(root,q);
        reverse(ppath);
        reverse(qpath);
        int i=0, j=0;
        while(i<ppath.size() and j<qpath.size())
        {
            if(ppath[i]!=qpath[j])
                break;
            i++;
            j++;
        }
        return ppath[i-1];
    }
};