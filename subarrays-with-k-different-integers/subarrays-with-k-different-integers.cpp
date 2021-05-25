class Solution {
public:
    int atostK(vector<int>& nums, int k)
    {
        int s=0, e=0, count=0, ans=0, n=nums.size();
        vector<int> freq(20001,0);
        while(e<n)
        {
            if(freq[nums[e++]]++==0) count++;
            while(count>k)
            {
                if(freq[nums[s++]]--==1) count--;
            }
            ans += e-s;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
         return atostK(nums, k)-atostK(nums,k-1);
    }
};