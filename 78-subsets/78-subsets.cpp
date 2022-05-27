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
        count+=subset(idx+1,nums,ans,smallAns);
        return count;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> smallAns;
        vector<vector<int>> ans;
        int a = subset(0,nums,ans, smallAns);
        return ans;
    }
};