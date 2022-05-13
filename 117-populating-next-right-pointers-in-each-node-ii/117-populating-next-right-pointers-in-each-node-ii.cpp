/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)
            return root;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int s=q.size();
            if(s==1)
            {
                Node *node = q.front();
                q.pop();
                node->next=NULL;
                if(node->left!=NULL)
                    q.push(node->left);
                if(node->right!=NULL)
                    q.push(node->right);
                continue;
            }
            else
            {
                for(int i=0; i<s; i++)
                {
                    Node *node = q.front();
                    q.pop();
                    Node *rightNode = (q.empty() || i==s-1) ? NULL : q.front();
                        node->next=rightNode;
                    if(node->left!=NULL)
                        q.push(node->left);
                    if(node->right!=NULL)
                        q.push(node->right);
                }
            }
        }
        return root;
    }
};