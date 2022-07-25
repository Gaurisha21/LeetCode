class Solution {
public:
    int fib(int N, vector<int> &dp)
    {
        for(int n=0; n<=N; n++)
        {
            if(n<=1)
            {
                dp[n]=n;
                continue;
            }
            int ans = dp[n-1]+dp[n-2];
            dp[n] = ans;
        }
        return dp[N];
    }
    int fib(int n) {
        vector<int> dp(n+1,-1);
        return fib(n,dp);
    }
};