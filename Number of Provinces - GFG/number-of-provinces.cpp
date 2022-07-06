// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  void dfs(vector<vector<int>> &graph, int src, vector<int> &vis)
  {
      vis[src]=1;
      for(int i=0; i<graph[src].size(); i++)
      {
          if(vis[graph[src][i]]!=1)
            dfs(graph, graph[src][i], vis);
      }
  }
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int> vis(V,0);
        vector<vector<int>> graph(V);
         for(int i=0;i<V;i++)
           {
               for(int j=i+1;j<V;j++)
               {
                   if(adj[i][j]==1)
                   {
                       graph[i].push_back(j);
                       graph[j].push_back(i);
                   }
               }
           }
        int comp=0;
        for(int i=0; i<V; i++)
        {
            if(vis[i]!=1)
            {
                comp++;
                dfs(graph,i,vis);
            }
        }
        return comp;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}  // } Driver Code Ends