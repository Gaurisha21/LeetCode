// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  void bfs(vector<vector<int>> graph, vector<int> &vis, int src)
  {
      queue<int> q;
      q.push(src);
      while(!q.empty())
      {
          int size = q.size();
          for(int i=0; i<size; i++)
          {
              int vrt = q.front();
              q.pop();
              if(vis[vrt]==1)
                continue;
              vis[vrt]=1;
              for(int j=0; j<graph[vrt].size(); j++)
              {
                  if(vis[graph[vrt][j]]==0)
                  q.push(graph[vrt][j]);
              }
          }
      }
  }
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<vector<int>> graph(V);
        vector<int> vis(V,0);
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
                bfs(graph,vis,i);
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