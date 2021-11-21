class Solution {
public:
    int sol(int N, int M, string &s1, string &s2, vector<vector<int>> &dp)
    {
        for(int n=0; n<=N; n++)
        {
            for(int m=0; m<=M; m++)
            {
                if(n==0 || m==0)
                {
                    dp[n][m] = n==0 ? m : n;
                    continue;
                }
                // if(dp[n][m]!=-1)
                //     return dp[n][m];
                int insert = dp[n][m-1];//sol(n,m-1,s1, s2, dp);
                int deleted = dp[n-1][m];//sol(n-1,m,s1, s2, dp);
                int replace = dp[n-1][m-1];//sol(n-1,m-1,s1,s2,dp);
                if(s1[n-1]==s2[m-1])
                    dp[n][m] = replace;//sol(n-1,m-1,s1,s2,dp);
                else
                    dp[n][m] = min(min(insert,deleted),replace)+1;       
            }
        }
        return dp[N][M];
    }
    int minDistance(string s1, string s2) {
        int n=s1.length(), m=s2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        int ans = sol(n,m,s1,s2,dp);
        // for(vector<int>d : dp)
        // {
        //     for(int i: d)
        //         cout<<i<<"\t";
        //     cout<<endl;
        // }
        return ans;
    }
};