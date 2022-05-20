class Solution {
public:
    vector<vector<int>> twoSum(vector<int>& nums, int k, int s, int e) {
        vector<vector<int>> ans;
        while(s<e)
        {
            int sum=nums[s]+nums[e];
            if(sum==k)
            { 
                ans.push_back({nums[s],nums[e]});
                s++;
                e--;
                while(nums[s]==nums[s-1] and s<e) s++;
                while(nums[e]==nums[e+1] and s<e) e--;
            }
            else if(sum>k) e--;
            else s++;
        }
        return ans;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n;)
        {
            vector<vector<int>> arr=twoSum(nums,-nums[i], i+1, n-1);
            for(vector<int> ele:arr)
                ans.push_back({nums[i],ele[0],ele[1]});
            while(i<n-1 and nums[i]==nums[i+1]) i++;
            i++;
        }
        return ans;
    }
};