class Solution {
public:
    int numWays(int i, string s, vector<int> &dp)
    {
        if(i==s.length())
            return dp[i]=1;
        if(dp[i]!=-1)
            return dp[i];
        if(s[i]=='0')
            return 0;
        int count=0;
        int num = s[i]-'0';
        if(num>=1 and num<=9)
            count+=numWays(i+1,s,dp);
        if(i+1<s.length())
        {
            int num2 = num*10 + (s[i+1]-'0');
            if(num2>=10 and num2<=26)
                count+=numWays(i+2,s,dp);
        }
        return dp[i]=count;
    }
    int numDecodings(string s) {
        int n=s.length();
        vector<int> dp(n+1,-1);
        return numWays(0,s,dp);
    }
};