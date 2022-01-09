class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int s=0, e=0, n=nums.size(), count=0, ans=INT_MIN;
        while(e<n)
        {
            if(nums[e++]==0) count++;
            while(count>k)
                if(nums[s++]==0) count--;
            ans = max(ans, e-s);
        }
        return ans;
    }
};