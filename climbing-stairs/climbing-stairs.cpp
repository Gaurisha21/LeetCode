class Solution {
public:
    int step(int n, vector<int> &dp)
    {
        if(n<=1)
            return dp[n]=1;
        if(dp[n]!=-1)
            return dp[n];
        return dp[n] = step(n-1,dp)+step(n-2,dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return step(n,dp);
    }
};