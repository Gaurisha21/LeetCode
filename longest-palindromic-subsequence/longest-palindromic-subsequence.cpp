class Solution {
public:
    int longestPalindromeSubseq(string &s, int i, int j, vector<vector<int>> &dp)
    {
        if(i>=j)
            return dp[i][j] = (i==j ? 1 : 0);
        
        if(dp[i][j]!=0)
            return dp[i][j];
        if(s[i]==s[j])
        {
            return dp[i][j]=longestPalindromeSubseq(s,i+1, j-1, dp)+2;
        }
        else
            return dp[i][j] = max(longestPalindromeSubseq(s,i+1, j, dp),longestPalindromeSubseq(s,i, j-1, dp));
    }
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, (vector<int>(n,0)));
        return longestPalindromeSubseq(s,0,n-1,dp);
    }
};