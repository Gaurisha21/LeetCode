class Solution {
public:
    int permInf(vector<int> coins, vector<long> &dp, int tar)
    {
        if(tar==0)
            return dp[tar]=1;
        if(dp[tar]!=-1)
            return dp[tar];
        int count = 0;
        for (int ele : coins){
            if(tar-ele>=0)
                count+=permInf(coins,dp,tar-ele);
        }
        return dp[tar] = count;    
    }
    int combinationSum4(vector<int>& nums, int tar) {
        vector<long> dp(tar+1,-1);
        int idx=0;
        return permInf(nums,dp, tar);
    }
};