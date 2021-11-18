class Solution {
public:
    int sol(int i, int j, string &s, vector<vector<int>> &dp)
    {
        if(i>=j)
            return dp[i][j] = (i==j ? 1 : 0);
        // if(i==j-1)
        // {
        //     if(s[i]==s[j])
        //         return dp[i][j] = 2;
        //     return dp[i][j] = 1;
        // }
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s[i]==s[j])
            return dp[i][j]=2+sol(i+1,j-1,s,dp);
        else
            return dp[i][j] = max(sol(i+1, j, s, dp),sol(i, j-1, s, dp));
    }
    int longestPalindromeSubseq(string s) {
        vector<vector<int>>dp(s.length(),vector<int>(s.length(),-1));
        return sol(0,s.length()-1, s, dp);
    }
};