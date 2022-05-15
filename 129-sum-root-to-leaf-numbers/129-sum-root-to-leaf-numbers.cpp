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
    int vecToNum(vector<int> arr)
    {
        int a=0, num=0;
        for(int i=0; i<arr.size(); i++)
            num+=(arr[i]*pow(10,a++));
        return num;
    }
    vector<vector<int>> binaryTreePaths(TreeNode* root) {
       if(root==NULL) return {};
       if(root->left==NULL and root->right==NULL)
           return {{root->val}};
        vector<vector<int>> ans;
        vector<vector<int>> lans= binaryTreePaths(root->left);
        for(vector<int> s : lans)
        {
            s.push_back(root->val);
            ans.push_back(s);
        }
        vector<vector<int>> rans = binaryTreePaths(root->right);
        for(vector<int> s : rans)
        {
            s.push_back(root->val);
            ans.push_back(s);
        }
        return ans;        
    }
    int sumNumbers(TreeNode* root) {
        vector<vector<int>> ans=binaryTreePaths(root);
        int num=0;
        for(vector<int> smallAns : ans)
            num+=vecToNum(smallAns);
        return num;
    }
};