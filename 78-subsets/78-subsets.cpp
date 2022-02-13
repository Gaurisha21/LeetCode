class Solution {
public:
    int subset(int idx, vector<int>& nums, vector<vector<int>> &ans, vector<int> &arr)
    {
        if(idx==nums.size())
        {
            ans.push_back(arr);
            return 1;
        }
        int count=0, t = nums[idx];
        vector<int> ARR = arr;
        ARR.push_back(t);
        count+=subset(idx+1,nums,ans,ARR);
        count+=subset(idx+1,nums,ans,arr);
        return count;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> arr;
        int a = subset(0,nums,ans,arr);
        return ans;
    }
};