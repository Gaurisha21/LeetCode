class Solution {
public:
    int lps(int i, int j, string &s, vector<vector<int>> &dp)
    {
        if(i>=j)
            return dp[i][j] = (i==j ? 1 : 0);
        if(dp[i][j]!=-1)
            return dp[i][j];
        int count=0;
        if(s[i]==s[j])
            count=lps(i+1,j-1,s,dp)+2;
        else
            count=max(lps(i+1,j,s,dp),lps(i,j-1,s,dp));
        return dp[i][j]=count;
    }
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return lps(0,n-1,s,dp);
    }
};