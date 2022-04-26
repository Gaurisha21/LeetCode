// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  void burningNode(Node *root, int time, Node *blocked, vector<vector<int>> &ans)
  {
      if(root==NULL || root==blocked)
        return;
      if(time==ans.size())
        ans.push_back({});
      ans[time].push_back(root->data);
      burningNode(root->left,time+1,blocked,ans);
      burningNode(root->right,time+1,blocked,ans);
  }
  int burnTree(Node *root, int target, vector<vector<int>> &ans)
  {
      if(root==NULL)
        return -1;
      if(root->data==target)
      {
          burningNode(root,0,NULL,ans);
          return 1;
      }
      int l = burnTree(root->left,target,ans);
      if(l!=-1)
      {
          burningNode(root,l,root->left,ans);
          return l+1;
      }
      int r = burnTree(root->right,target,ans);
      if(r!=-1)
      {
          burningNode(root,r,root->right,ans);
          return r+1;
      }
      return -1;
  }
    int minTime(Node* root, int target) 
    {
        vector<vector<int>> ans;
        burnTree(root,target, ans);
        // for(vector<int> ele:ans)
        // {
        //     for(int e : ele)
        //         cout<<e<<" ";
        //     cout<<endl;
        // }
        return ans.size()-1;
    }
};

// { Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}
  // } Driver Code Ends