class Solution {
public:
    int tri(int n, vector<int> &dp)
    {
        if(n==0 || n==1 || n==2)
            return n==2 ? 1 : n;
        if(dp[n]!=-1)
            return dp[n];
        int ans = tri(n-1,dp)+tri(n-2,dp)+tri(n-3,dp);
        return dp[n]=ans;
    }
    int tribonacci(int n) {
        vector<int> dp(n+1,-1);
        return tri(n,dp);
    }
};