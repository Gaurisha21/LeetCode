class Solution {
public:
    int sol(int n, int m, string &s1, string &s2, vector<vector<int>> &dp)
    {
        if(n==0 || m==0)
            return dp[n][m] = 0;
        if(dp[n][m] != -1)
            return dp[n][m];
        if(s1[n-1]==s2[m-1])
            dp[n][m] = sol(n-1,m-1,s1,s2,dp)+1;
        else
            dp[n][m] = max(sol(n-1,m,s1,s2,dp),sol(n,m-1,s1,s2,dp));
        return dp[n][m];
    }
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        vector<vector<int>> dp (n+1, vector<int>(m+1,-1));
        return sol(n,m,s1,s2,dp);
    }
};