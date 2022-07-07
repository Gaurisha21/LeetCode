class Solution {
public:
    int coinChange(int n, int tar, vector<vector<int>> &dp, vector<int> &coin, int idx)
  {
      if(idx==n || tar==0)
          return dp[tar][idx] = tar==0? 1 : 0;
      if(dp[tar][idx]!=-1)
        return dp[tar][idx];
      int count=0; 
      for(int i=idx; i<n; i++)
      {
          if(tar-coin[i]>=0)
          {
              int x = tar-coin[i];
              count+=coinChange(n,x,dp,coin,i);
          }
      }
      return dp[tar][idx]=count;
  }
    int change(int target, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(target+1,vector<int>(n,-1));
        return coinChange(n,target,dp,coins,0);
    }
};