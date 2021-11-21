class Solution {
public:
    int sol(int n, int m, string &s1, string &s2, vector<vector<int>> &dp)
    {
        if(n==0 || m==0)
            return dp[n][m] = n==0 ? m : n;
        if(dp[n][m]!=-1)
            return dp[n][m];
        int insert = sol(n,m-1,s1, s2, dp);
        int deleted = sol(n-1,m,s1, s2, dp);
        int replace = sol(n-1,m-1,s1,s2,dp);
        if(s1[n-1]==s2[m-1])
            dp[n][m] = sol(n-1,m-1,s1,s2,dp);
        else
            dp[n][m] = min(min(insert,deleted),replace)+1;
        return dp[n][m];
    }
    int minDistance(string s1, string s2) {
        int n=s1.length(), m=s2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        return sol(n,m,s1,s2,dp);
    }
};