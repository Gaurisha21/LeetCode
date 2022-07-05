// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
int dfs(vector<vector<int>> &graph, vector<int> &vis, int src, int dest)
{
    if(src==dest)
        return 1;
    vis[src]=1;
    int count=0;
    for(int i=0; i<graph[src].size(); i++)
    {
        if(vis[graph[src][i]]!=1)
            count+=dfs(graph,vis,graph[src][i],dest);
    }
    vis[src]=0;
    return count;
}
	int possible_paths(vector<vector<int>>edges, int n, int s, int d){
	    vector<vector<int>> graph(n);
	    vector<int> vis(n,0);
	    for(int i=0; i<edges.size(); i++)
	        graph[edges[i][0]].push_back(edges[i][1]);
	    return dfs(graph,vis,s,d);
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, s, d;
		cin >> n >> m >> s >> d;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			edges.push_back({u,v});
		}
		Solution obj;
		int ans = obj.possible_paths(edges, n, s, d);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends