class Solution {
public:
    int dp[201][201];
    int solve(vector<vector<int>>&grid,int i,int j)
    {
        if(i<0||j<0)
             return INT_MAX;
        if(dp[i][j]!=-1)
            return dp[i][j];
         if(i==0&&j==0)
            return grid[0][0];
        int a1=solve(grid,i-1,j);
        int a2=solve(grid,i,j-1);
        dp[i][j]=grid[i][j]+min(a1,a2);
        return dp[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) 
    {
       int n=grid.size(),m=grid[0].size();
       memset(dp,-1,sizeof(dp));
       return solve(grid,n-1,m-1);
    }
};