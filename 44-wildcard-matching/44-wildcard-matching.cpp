class Solution {
public:
    string removeStar(string p)
    {
        int n=p.length();
        stack<char> st;
        st.push('1');
        for(int i=0; i<n; i++)
        {
            if(st.top()!='1' and st.top()=='*' and p[i]=='*')
            {
                st.pop();
                st.push(p[i]);
            }
            else 
                st.push(p[i]);
        }
        string ans = "";
        while(st.top()!='1')
        {
            char a = st.top();
            st.pop();
            ans+=a;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    int wildCard(int n, int m, string &s, string &p, vector<vector<int>> &dp)
    {
        if(n==0 || m==0)
        {
            if(n==0 and m==0)
                return dp[n][m]=1;
            else if(m==1 and p[m-1]=='*')
                return dp[n][m]=1;
            else 
                return dp[n][m]=0;
        }
        if(dp[n][m]!=-1)
            return dp[n][m];
        
        if(s[n-1]==p[m-1] || p[m-1]=='?')
            dp[n][m]=wildCard(n-1,m-1,s,p,dp);
        else if(p[m-1]=='*')
        {
            bool res = false;
            res = res || wildCard(n-1,m,s,p,dp);
            res = res || wildCard(n,m-1,s,p,dp);
            
            dp[n][m]= res ? 1 : 0;
        }
        else 
            dp[n][m]=0;
        return dp[n][m];
            
    }
    bool isMatch(string s, string p) {
        p=removeStar(p);
        // cout<<p<<endl;
        int n=s.length(), m=p.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return wildCard(n,m,s,p,dp);
    }
};