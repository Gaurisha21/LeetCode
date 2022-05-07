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
    class bstPair{
      public: 
        bool isBal=true;
        int h=-1;
    };
    bstPair isBalanced_(TreeNode* root) 
    {
        if(root==NULL)
        {
            bstPair base;
            return base;//new bstPair();
        }
        bstPair l=isBalanced_(root->left);
        bstPair r=isBalanced_(root->right);
        
        bstPair ans;
        ans.isBal=l.isBal && r.isBal;
        if(ans.isBal && abs(l.h-r.h)<2)
            ans.h=max(l.h, r.h)+1;
        else
            ans.isBal=false;
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        return isBalanced_(root).isBal;
    }
};