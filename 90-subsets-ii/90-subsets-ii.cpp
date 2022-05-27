class Solution {
public:
    int subset(int idx, vector<int> nums, vector<vector<int>> &ans, vector<int> &smallAns)
    {
        if(idx==nums.size())
        {
            ans.push_back(smallAns);
            return 1;
        }
        int count=0;
        vector<int> temp=smallAns;
        temp.push_back(nums[idx]);
        count+=subset(idx+1,nums,ans,temp);
        while(idx+1<nums.size() and nums[idx]==nums[idx+1])idx++;
        count+=subset(idx+1,nums,ans,smallAns);
        return count;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> smallAns;
        vector<vector<int>> ans;
        int a = subset(0,nums,ans, smallAns);
        return ans;
    }
};