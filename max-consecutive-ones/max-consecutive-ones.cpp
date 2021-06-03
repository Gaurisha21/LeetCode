class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int s=0, e=0, n=nums.size(), len=0;
        while(e<n)
        {
            if(nums[e++]==0) s=e;
            len=max(len, e-s);
        }
        return len;
    }
};