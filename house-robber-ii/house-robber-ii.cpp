class Solution {
public:
    int rob(int i, int n, vector<int> &dp, vector<int> nums)
    {
        if(nums.size()<=2)
        {
            int mx=INT_MIN;
            for(int i=0; i<nums.size(); i++)
                mx = max(mx, nums[i]);
            return mx;
        }
        if(i>=n)
            return dp[i] = 0;
        if(i==n-1)
            return dp[i] = nums[i];
        if(dp[i]!=-1)
            return dp[i];
        int selected = rob(i+2,n,dp,nums)+nums[i];
        int notSelected = rob(i+1,n,dp,nums);
        return dp[i] = max(selected, notSelected);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp1(n+1,-1);
        vector<int> dp2(n+1,-1);
        int wz = rob(0,n-1,dp1,nums);
        int woz = rob(1,n,dp2,nums);
        return max(wz, woz);
    }
};