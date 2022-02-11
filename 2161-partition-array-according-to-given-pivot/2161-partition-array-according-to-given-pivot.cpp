class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int t) {
        int n=nums.size();
        vector<int> ans, small, equal, big;
        for(int i=0; i<n; i++)
        {
            if(nums[i]<t) small.push_back(nums[i]);
            else if(nums[i]==t) equal.push_back(nums[i]);
            else big.push_back(nums[i]);
        }
        for(int i=0; i<small.size(); i++)
            ans.push_back(small[i]);
        for(int i=0; i<equal.size(); i++)
            ans.push_back(equal[i]);
        for(int i=0; i<big.size(); i++)
            ans.push_back(big[i]);
        return ans;
    }
};