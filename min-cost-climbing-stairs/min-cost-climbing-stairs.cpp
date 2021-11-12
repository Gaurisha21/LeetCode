class Solution {
public:
    int step(int n, vector<int> cost, vector<int>&dp)
    {
        if(n<=1)
            return dp[n]=cost[n];
        if(dp[n]!=-1)
            return dp[n];
        int minCost = min(step(n-1,cost,dp),step(n-2,cost,dp));
        return dp[n] = minCost + (n == cost.size() ? 0 : cost[n]);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,-1);
        return step(n,cost,dp);
    }
};