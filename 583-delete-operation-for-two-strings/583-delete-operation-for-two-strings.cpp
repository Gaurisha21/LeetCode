class Solution {
public:
    int minDist(string &s1, string &s2, int n, int m, vector<vector<int>> &dp)
    {
        if(n==0 || m==0)
            return dp[n][m]=max(n,m);
        
        if(dp[n][m]!=-1)
            return dp[n][m];
        
        if(s1[n-1]==s2[m-1])
            dp[n][m]=minDist(s1,s2,n-1,m-1,dp);
        else
            dp[n][m]=min(minDist(s1,s2,n-1,m,dp),minDist(s1,s2,n,m-1,dp))+1;
        return dp[n][m];
    }
    int minDistance(string s1, string s2) {
        int n=s1.length(), m=s2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        return minDist(s1,s2,n,m,dp);
    }
};