class Solution {
public:
    int minCostClimbingStairs(int n, vector<int>& cost, vector<int>& dp) {
        if(n<=1) return dp[n] = cost[n];
        if(dp[n]!=-1) return dp[n];
        int minCost = min(minCostClimbingStairs(n-1,cost, dp), minCostClimbingStairs(n-2,cost,dp));
        return dp[n] = minCost + (n == cost.size() ? 0 : cost[n]);
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,-1);
        return minCostClimbingStairs(n,cost, dp);
    }
};