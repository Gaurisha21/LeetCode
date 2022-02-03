class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size(), s=0, e=0, count=0, len=0;
        while(e<n)
        {
            if(nums[e++]==0) count++;
            while(count>1)
                if(nums[s++]==0) count--;
            len = max(len,(e-s));
        }
        return len-1;
    }
};