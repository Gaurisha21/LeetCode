class Solution {
public:
    string lpsDP(string &s)
    {
        int n=s.length(), st=0, e=0, len=1;
        vector<vector<bool>> dp(n+1, vector<bool>(n+1,false));
        for(int gap=0; gap<n; gap++)
        {
            for(int i=0, j=gap; j<n; i++, j++)
            {
                if(gap==0)
                {
                    dp[i][j]=true;
                    if(len<(j-i+1))
                    {
                        len = j-i+1;
                        st=i;
                    }
                }
                else if(gap==1 and s[i]==s[j])
                {
                    dp[i][j]=true;
                    if(len<(j-i+1))
                    {
                        len = j-i+1;
                        st=i;
                    }
                }
                else
                {
                    dp[i][j] = s[i]==s[j] and dp[i+1][j-1];
                    if(dp[i][j] and len<(j-i+1))
                    {
                        len = j-i+1;
                        st=i;
                    }
                }
            }
        }
        return s.substr(st,len);
    }
    string longestPalindrome(string s) {
        return lpsDP(s);
    }
};