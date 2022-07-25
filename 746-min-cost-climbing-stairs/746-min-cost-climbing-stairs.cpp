class Solution {
public:
    int minCost(int n, vector<int> &dp, vector<int> cost)
    {
        if(n<=1)
            return dp[n]=cost[n];
        if(dp[n]!=-1)
            return dp[n];
        int amt = (n==cost.size() ? 0 :cost[n])+min(minCost(n-1,dp,cost),minCost(n-2,dp,cost));
        return dp[n]=amt;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1,-1);
        return minCost(n,dp,cost);
    }
};