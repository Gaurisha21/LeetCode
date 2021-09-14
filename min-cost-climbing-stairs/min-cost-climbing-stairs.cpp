class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int N=cost.size();
        vector<int>dp(N,0);
        for(int n=0; n<N; n++)
        {
            if(n<=1)
            {
                dp[n] = cost[n];
                continue;
            }
            
            int minCost = min(dp[n-1], dp[n-2])+cost[n];
            
            dp[n] = minCost;
        }
        return min(dp[N-1],dp[N-2]);
    }
};