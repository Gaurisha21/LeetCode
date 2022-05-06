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
        {
            ans+="#,";
            return;
        }
        ans+=(to_string(root->val)+",");
        serialize(root->left, ans);
        serialize(root->right, ans);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans="";
        if (root == NULL)
            return ans;
        serialize(root,ans);
        // cout<<ans<<endl;
        return ans;
    }
    
    int idx=0;
    TreeNode* deserialize(vector<int> data)
    {
        if(idx>=data.size() || data[idx]==-1001)
        {
            idx++;
            return NULL;
        }
        TreeNode *node = new TreeNode(data[idx++]);
        node->left=deserialize(data);
        node->right=deserialize(data);
        return node;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string ans) {
        vector<int>a;
        string x="";
        for(int i=0;i<ans.length();i++){
            if(ans[i]!=','){
            x+=ans[i];
            }
            else{
                if(x=="#")
                a.push_back(-1001);
                else
                a.push_back(stoi(x));
                x="";
            }
        }
        
        return deserialize(a);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));