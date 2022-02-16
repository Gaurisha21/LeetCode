class Solution {
public:
    int coinChangeMin(vector<int> coin, int tar, vector<int> &dp)
    {
        if(tar==0)
            return 0;
        if(dp[tar]!=int(1e9)) return dp[tar];
        int count=int(1e8);
        for(int ele:coin)
        {
            if(tar-ele>=0)
                count = min(count, coinChangeMin(coin,tar-ele,dp)+1);
        }
        return dp[tar]=count;
    }
    int coinChange(vector<int>& coin, int tar) {
        if(tar==0) return 0;
        vector<int> dp(tar+1,int(1e9));
        int r = coinChangeMin(coin,tar,dp);
        // for(int i : dp) cout<<i<<" ";
        return r!=int(1e8) ? r:-1;
    }
};