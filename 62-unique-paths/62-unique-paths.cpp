class Solution {
public:
    int path(int sr, int sc, int er, int ec, vector<vector<int>> dir, vector<vector<int>> &dp)
    {
        if(sr==er and sc==ec)
            return dp[sr][sc]=1;
        if(dp[sr][sc]!=-1)
            return dp[sr][sc];
        int count=0; 
        for(int d=0; d<dir.size(); d++)
        {
            int r=sr+dir[d][0];
            int c=sc+dir[d][1];
            if(r>=0 and r<er+1 and c>=0 and c<ec+1)
            {
                count+=path(r,c,er,ec,dir,dp);
            }
        }
        return dp[sr][sc]=count;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,-1)), dir{{0,1},{1,0}};
        return path(0,0,m-1,n-1,dir,dp);
    }
};