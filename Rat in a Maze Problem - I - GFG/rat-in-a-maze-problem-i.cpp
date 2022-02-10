// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++



class Solution{
    public:
    int floodFill(int sr, int sc, vector<vector<int>> &vis, vector<vector<int>> &dir, vector<string> &dirS, vector<string> &res, string psf)
    {
        int n = vis.size(), m = vis[0].size();

        if (sr == n - 1 && sc == m - 1) {
            res.push_back(psf);
            return 1;
        }

        int count = 0;
        vis[sr][sc] = 0;
        for (int d = 0; d < dir.size(); d++) {
            int r = sr + dir[d][0];
            int c = sc + dir[d][1];

            if (r >= 0 && c >= 0 && r < n && c < m && vis[r][c]==1)
                count += floodFill(r, c, vis, dir, dirS, res, psf + dirS[d]);
        }
        vis[sr][sc] = 1;
        return count;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> dirS = {"D","L","R","U"};
        vector<vector<int>> dir = {{1,0},{0,-1},{0,1},{-1,0}};
        vector<string> res;
        if(m[0][0]==0 || m[n-1][n-1]==0) return res;
        int count = floodFill(0, 0, m, dir, dirS, res, "");
        return res;
        
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends