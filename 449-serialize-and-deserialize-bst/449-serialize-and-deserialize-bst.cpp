/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void serialize(TreeNode *root, string &ans)
    {
        if(root==NULL)
            return;
        ans += to_string(root->val) + " ";
        serialize(root->left, ans);
        serialize(root->right, ans);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        serialize(root, ans);
        // cout<<ans<<endl;
        return ans;
    }
    
    TreeNode *bstFromPreorder(vector<int> &preorder, int lr, int rr, vector<int> &idx)
    {
        int i = idx[0];
        if (i >= preorder.size() || preorder[i] < lr || preorder[i] > rr)
            return nullptr;

        TreeNode *root = new TreeNode(preorder[i]);
        idx[0]++;

        root->left = bstFromPreorder(preorder, lr, root->val, idx);
        root->right = bstFromPreorder(preorder, root->val, rr, idx);

        return root;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.length() == 0)
            return nullptr;
        stringstream ss(data);
        string word;

        vector<int> preorder, idx(1,0);
        while (ss >> word)
        {
            int val = stoi(word);
            preorder.push_back(val);
        }
        int n=preorder.size()-1;
        return bstFromPreorder(preorder, INT_MIN, INT_MAX, idx);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;