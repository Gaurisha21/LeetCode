// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    // int serchNode(vector<vector<int>> graph, int src, int dest)
    // {
    //     for(int i=0; i<graph[src].size(); i++)
    //     {
    //         if(graph[src][i]==dest)
    //             return i;
    //     }
    //     return -1;
    // }
    bool ans=false;
    void cycle(int n, int m, vector<vector<int>> &graph, vector<int> &vis, int src, int osrc, int edgeCount, string &psf)
    {
        if(edgeCount==n)
        {
            // cout<<psf<<endl;
            ans = true;
            return;
        }
        vis[src]=1;
        for(int i=0; i<graph[src].size(); i++)
        {
            if(vis[graph[src][i]]!=1)
            {
                string p = psf + to_string(src);
                cycle(n,m,graph,vis,graph[src][i],osrc,edgeCount+1,p);
            }
        }
        vis[src]=0;
    }
    
    bool check(int n,int m,vector<vector<int>> edges)
    {
        vector<vector<int>> graph(n+1);
	    vector<int> vis(n+1,0);
	    for(int i=0; i<edges.size(); i++)
	    {
	        graph[edges[i][0]].push_back(edges[i][1]);
	        graph[edges[i][1]].push_back(edges[i][0]);
	    }
        // int i=0;
        // for(vector<int> arr : graph)
        // {
        //     cout<<i++<<"-> ";
        //     for(int ele : arr)
        //         cout<<ele<<" ";
        //     cout<<endl;
        // }
        string psf = "";
        for(int i=1; i<=n; i++)
            cycle(n,m,graph,vis,i,i,1,psf);
        return ans;
    }
};
 

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
    	int N,M,X,Y;
    	cin>>N>>M;
    	vector<vector<int>> Edges;
    	for(int i=0;i<M;i++)
    	{
    		cin>>X>>Y;
    		Edges.push_back({X,Y});
    	}
    	Solution obj;
    	if(obj.check(N,M,Edges)){
    		cout<<"1"<<endl;
    	}
    	else
    	cout<<"0"<<endl;
	}
}  // } Driver Code Ends