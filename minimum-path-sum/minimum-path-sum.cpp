class Solution {
public:
    int solve(vector<vector<int>>&grid,int i,int j, vector<vector<int>> &dp)
    {
        int n=grid.size(),m=grid[0].size();
        if(i>=n||j>=m)
             return INT_MAX;
        if(dp[i][j]!=-1)
            return dp[i][j];
         if(i==n-1 && j==m-1)
            return grid[i][j];
        int a1=solve(grid,i+1,j,dp);
        int a2=solve(grid,i,j+1,dp);
        dp[i][j]=grid[i][j]+min(a1,a2);
        return dp[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) 
    {
       int n=grid.size(),m=grid[0].size();
       vector<vector<int>> dp(n,vector<int>(m,-1)); 
       return solve(grid,0,0,dp);
    }
};