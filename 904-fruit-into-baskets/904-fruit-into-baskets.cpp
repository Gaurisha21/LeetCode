class Solution {
public:
    int karr(vector<int> nums, int k)
    {
        vector<int> freq(100001,0);
        int s=0, e=0, n=nums.size(), count=0, ans=0; 
        while(e<n)
        {
            if(freq[nums[e++]]++==0) count++;
            while(count>k)
                if(freq[nums[s++]]--==1) count--;
            ans = max(ans,(e-s));
        }
        return ans;
    }
    int totalFruit(vector<int>& nums) {
        return karr(nums,2);
    }
};