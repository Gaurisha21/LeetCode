class Solution {
public:
    int nd(int i, string s, vector<int> &dp)
    {
        int n=s.length();
        if(i==n)
            return dp[i]=1;
        if(dp[i]!=-1)
            return dp[i];
        char ch1 = s[i];
        if(ch1=='0')
            return 0;
        int count=0;
        count+=nd(i+1,s,dp);
        if(i<n-1)
        {
            char ch2 = s[i+1];
            int num = (ch1-'0')*10 + (ch2-'0');
            if(num<=26)
                count+=nd(i+2,s,dp);
        }
        return dp[i] = count;
    }
    int numDecodings(string s) {
        int n=s.length();
        vector<int>dp(n+1,-1);
        return nd(0,s,dp);
    }
};