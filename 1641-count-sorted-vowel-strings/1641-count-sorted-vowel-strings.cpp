class Solution {
public:
    int countVowelStrings(int n, int idx, vector<char> str, string &ans, vector<vector<int>> &dp) 
    {
        int m=ans.length();
        if(idx==str.size() || m==n)
        {
            if(m==n)
                return dp[m][idx]=1;
            return 0;
        }
        if(dp[m][idx]!=-1)
            return dp[m][idx];
        int count=0;
        for(int i=idx; i<str.size(); i++)
        {
            string p=ans+str[i];
            count+=countVowelStrings(n,i,str,p,dp);
        }
        return dp[m][idx]=count;
    }
    int countVowelStrings(int n) {
        vector<char> str={'a','e','i','o','u'};
        string ans="";
        vector<vector<int>> dp(n+1,vector<int>(5, -1));
        return countVowelStrings(n,0,str,ans,dp);
    }
};