// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
public:
int mod = int(1e9+7);
    int floodFill(int sr, int sc, vector<vector<int>> &vis, vector<vector<int>> &dir, vector<vector<int>> &dp)
{
    int n = vis.size(), m = vis[0].size();
    if (sr == n - 1 && sc == m - 1)
    {
        return dp[sr][sc] = 1;
    }
    if(dp[sr][sc]!=-1) return dp[sr][sc];
    
    vis[sr][sc] = 1; // block
    int count = 0;
    for (int d = 0; d < dir.size(); d++)
    {
        int r = sr + dir[d][0];
        int c = sc + dir[d][1];

        if (r >= 0 && c >= 0 && r < n && c < m && vis[r][c] == 0)
        {
            count += floodFill(r, c, vis, dir,dp);
        }
    }

    vis[sr][sc] = 0; // unblock
    return dp[sr][sc] = (count%mod);
}

int FindWays(int n, int m, vector<vector<int>> blocked_cells)
{
    vector<vector<int>> dp (n+1, vector<int>(m+1,-1));
    vector<vector<int>> vis(n + 1, vector<int>(m + 1, 0));
    for (vector<int> &bc : blocked_cells)
    {
        vis[bc[0]][bc[1]] = 1; // 1 means blocked
    }

    if (vis[1][1] == 1 || vis[n][m] == 1)
        return 0;

    vector<vector<int>> dir = {{1, 0}, {0, 1}};

    return floodFill(1, 1, vis, dir, dp);
}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, k;
		cin >> n >> m >> k;
		vector<vector<int>>blocked_cells;
		for(int i = 0; i < k; i++){
			int x, y;
			cin >> x >> y;
			blocked_cells.push_back({x, y});
		}
		Solution obj;
		int ans = obj.FindWays(n, m, blocked_cells);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends