class Solution {
public:
    int mod = (int)(1e9+7);
    long  numWays(int i, string &s, vector<long int> &dp)
    {
        if(i==s.length())
            return dp[i]=1;
        if(dp[i]!=-1)
            return dp[i];
        if(s[i]=='0')
            return 0;
        long int count=0;
        if(s[i]=='*')
        {
            count=(count+9*numWays(i+1,s,dp))%mod;
            if(i+1<s.length())
            {
                char ch2 = s[i+1];
                if(ch2>='0' && ch2<='6')
                    count = (count + 2*numWays(i+2,s,dp))%mod;
                else if(ch2>='7' && ch2<='9')
                    count =(count + numWays(i+2,s,dp))%mod;
                else
                    count =(count + 15*numWays(i+2,s,dp))%mod;
            }
        }
        else
        {
            int num1 = s[i]-'0';
            count=(count+numWays(i+1,s,dp))%mod;
            if(i+1<s.length())
            {
                if(num1==1 and s[i+1]=='*')
                    count=(count+9*numWays(i+2,s,dp))%mod;
                else if(num1==2 and s[i+1]=='*')
                    count=(count+6*numWays(i+2,s,dp))%mod;
                else if(s[i+1]!='*')
                {
                    int num2 = num1*10 + (s[i+1]-'0');
                    if(num2<=26)
                        count=(count+numWays(i+2,s,dp))%mod;
                }
            }
        }
        return dp[i]=count;
    }
    int numDecodings(string s) {
        int n=s.length();
        vector<long int> dp(n+1,-1);
        return numWays(0,s,dp);
    }
};