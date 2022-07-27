class Solution {
public:
    int wordBreak(string &s, vector<string>& wordDict, vector<int> &dp)
    {
        int n=s.length();
        if(n==0)
            return dp[n]=1;
        if(dp[n]!=-1)
            return dp[n];
        
        bool res = false;
        for(int idx=0; idx<n; idx++)
        {
            string part = s.substr(0,idx+1);
            if(find(wordDict.begin(),wordDict.end(),part)!=wordDict.end())
            {
                string remainPart = s.substr(idx+1);
                // cout<<remainPart<<endl;
                res = res || wordBreak(remainPart,wordDict,dp)==1;
            }
        }
        return dp[n]=res ? 1 : 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();
        vector<int> dp(n+1,-1);
        int ans = wordBreak(s,wordDict,dp);
        // cout<<ans<<endl;
        return ans;
    }
};