class Solution {
public:
    int path(vector<vector<int>>& grid, int sr, int sc, int er, int ec, vector<vector<int>> dir, vector<vector<int>> &dp)
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
            if(r>=0 and r<er+1 and c>=0 and c<ec+1 and grid[r][c]==0)
            {
                count+=path(grid, r,c,er,ec,dir,dp);
            }
        }
        return dp[sr][sc]=count;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        if(grid[0][0]==1)
            return 0;
        vector<vector<int>> dp(m, vector<int>(n,-1)), dir{{0,1},{1,0}};
        return path(grid,0,0,m-1,n-1,dir,dp);
    }
};