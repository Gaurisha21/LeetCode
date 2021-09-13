class Solution {
public:
    int uniquePaths(int sr, int sc, int er, int ec, vector<vector<int>> &dp, vector<vector<int>> dir) {
        if (er == sr && ec == sc) {
            return dp[sr][sc] = 1;
        }

        if (dp[sr][sc] != 0)
            return dp[sr][sc];

        int count = 0;
        for (vector<int>d : dir) {
            int r = sr + d[0], c = sc + d[1];
            if (r >= 0 && c >= 0 && r < dp.size() && c < dp[0].size()) {
                count += uniquePaths(r, c, er, ec, dp, dir);
            }
        }

        return dp[sr][sc] = count;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dir{{0,1},{1,0}};
        vector<vector<int>> dp(m,vector<int>(n,0));
        return uniquePaths(0,0,m-1,n-1,dp,dir);
    }
};