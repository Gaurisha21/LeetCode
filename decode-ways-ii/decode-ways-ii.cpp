class Solution {
public:
    int mod = (int) 1e9+7;
    long sol(int i, string &s, vector<long>&dp)
    {
        int n=s.length();
        if(i==n)
            return dp[i]=1;
        if(dp[i]!=-1)
            return dp[i];
        char ch1 = s[i];
        if(ch1 == '0')
            return dp[i]=0;
        long count = 0;
        if(ch1=='*')
        {
            count=(count+9*sol(i+1,s,dp))%mod;
            if(i<n-1)
            {
                char ch2 = s[i+1];
                if(ch2>='0' && ch2<='6')
                    count = (count + 2*sol(i+2,s,dp))%mod;
                else if(ch2>='7' && ch2<='9')
                    count =(count + sol(i+2,s,dp))%mod;
                else
                    count =(count + 15*sol(i+2,s,dp))%mod;
            }
        }
        else
        {
            count =(count+ sol(i+1,s,dp))%mod;
            if(i<n-1)
            {
                char ch2 = s[i+1];
                if(ch1=='1' and ch2=='*')
                    count=(count+ 9*sol(i+2,s,dp))%mod;
                else if(ch1=='2' and ch2=='*')
                    count=(count + 6*sol(i+2,s,dp))%mod;
                else if(ch2!='*')
                {
                    int num = (ch1-'0')*10 + (ch2-'0');
                    // cout<<num<<" "<<ch1<<" "<<ch2;
                    if(num<=26)
                        count=(count+ sol(i+2,s,dp))%mod;
                }
            }
        }
        return dp[i]=count;
    }
    int numDecodings(string s) {
        int n=s.length();
        vector<long> dp(n+1,-1);
        long ans = sol(0,s,dp);
        return (int)ans;
    }
};