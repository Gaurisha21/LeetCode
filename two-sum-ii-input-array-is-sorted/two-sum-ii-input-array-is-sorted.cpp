class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int s, e;
        vector<int> ans;
        s=0; e=nums.size()-1;
        while(s<e)
        {
            if((nums[s]+nums[e])==target) 
            {
                ans.push_back(s+1);
                ans.push_back(e+1);
                break;
            }
            else if((nums[s]+nums[e])>target) e--;
            else s++;
        }
        return ans;
    }
};