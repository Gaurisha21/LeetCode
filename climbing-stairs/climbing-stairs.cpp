class Solution {
public:
    int climbStairs_dp(int N, vector<int> &dp)
{

    for (int n = 0; n <= N; n++)
    {
        if (n <= 1)
        {
            dp[n] = 1;
            continue;
        }

        dp[n] = dp[n - 1] + dp[n - 2]; //climbStairs_memo(n - 1, dp) + climbStairs_memo(n - 2, dp);
    }

    return dp[N];
}

int climbStairs(int n)
{
    vector<int> dp(n + 1, 0);
    return climbStairs_dp(n, dp);
}

};