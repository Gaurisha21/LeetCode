class Solution {
public:
    int atmostK(vector<int>& nums, int goal)
    {
        int s=0, e=0, n=nums.size(), count=0, ans=0;
        while(e<n)
        {
            if(nums[e++]==1) count++;
            while(count>goal)
                if(nums[s++]==1) count--;
            ans += (e-s);
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmostK(nums, goal)-(goal!=0? atmostK(nums,goal-1):0);
    }
};