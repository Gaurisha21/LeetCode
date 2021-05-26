class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int s=0, e=0, count=0, len=0, n=nums.size();
        while(e<n)
        {
            if(nums[e++]==0) count++;
            while(count==1)
            {
                if(nums[s++]==0) count--;
            }
            len = max(len, e-s);
        }
        return len;
    }
};