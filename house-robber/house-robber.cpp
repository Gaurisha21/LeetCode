class Solution {
public:
    int rob(int i, vector<int> &dp, vector<int> nums)
    {
        int n=nums.size();
        if(i>=n)
            return dp[i] = 0;
        if(i==n-1)
            return dp[i] = nums[i];
        if(dp[i]!=-1)
            return dp[i];
        int selected = rob(i+2,dp,nums)+nums[i];
        int notSelected = rob(i+1,dp,nums);
        return dp[i] = max(selected, notSelected);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        return rob(0,dp,nums);
    }
};