class Solution {
public:
    int sol(int n, int m, string &s, string &t, vector<vector<int>> &dp)
    {
        if(m==0)
            return dp[n][m] = 1;
        if(n<m)
            return dp[n][m] = 0;
        if(dp[n][m]!=-1)
            return dp[n][m];
        if(s[n-1]==t[m-1])
            dp[n][m] = sol(n-1,m-1,s,t,dp)+sol(n-1,m,s,t,dp);
        else
            dp[n][m] = sol(n-1,m,s,t,dp);
        return dp[n][m];
    }
    int numDistinct(string s, string t) {
        int n=s.length(),m=t.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return sol(n,m,s,t,dp);
    }
};