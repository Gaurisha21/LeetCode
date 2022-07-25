class Solution {
public:
    int path(int SR, int SC, int er, int ec, vector<vector<int>> dir, vector<vector<int>> &dp)
    {
        for(int sc=ec; sc>=0; sc--)
        {
            for(int sr=er; sr>=0; sr--)
            {
                if(sr==er and sc==ec)
                {
                    dp[sr][sc]=1;
                    continue;
                }
                int count=0; 
                for(int d=0; d<dir.size(); d++)
                {
                    int r=sr+dir[d][0];
                    int c=sc+dir[d][1];
                    if(r>=0 and r<er+1 and c>=0 and c<ec+1)
                    {
                        count+=dp[r][c];//path(r,c,er,ec,dir,dp);
                    }
                }
                dp[sr][sc]=count;
            }
        }
        return dp[0][0];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,-1)), dir{{0,1},{1,0}};
        return path(0,0,m-1,n-1,dir,dp);
    }
};