class Solution {
public:
    int uni(int sr, int sc, int er, int ec, vector<vector<int>> &dp, vector<vector<int>> &dir)
    {
        if(sr==er && sc==ec)
            return dp[sr][sc] = 1;
        if(dp[sr][sc]!=-1)
            return dp[sr][sc];
        int count=0;
        for(int d=0; d<dir.size();d++)
        {
            int r = sr + dir[d][0], c= sc + dir[d][1];
            if(r>=0 && c>=0 && r<dp.size() && c<dp[0].size())
                count+=uni(r,c,er,ec,dp, dir);
        }
        return dp[sr][sc] = count;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,-1));
        vector<vector<int>> dir = {{0,1},{1,0}};
        return uni(0,0,m-1,n-1,dp,dir);
    }
};