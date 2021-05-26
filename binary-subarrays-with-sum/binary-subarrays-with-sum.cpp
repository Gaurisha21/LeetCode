class Solution {
public:
    int atmost(vector<int>& nums, int goal)
    {
        int s=0, e=0, sum=0, ans=0, n=nums.size();
        while(e<n)
        {
            sum+=nums[e++]; 
            while(sum>goal)
            {
                sum-=nums[s++];
            }
            ans += e-s;
        }
        return ans;    
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmost(nums, goal) - (goal != 0 ? atmost(nums, goal-1):0);
    }
};