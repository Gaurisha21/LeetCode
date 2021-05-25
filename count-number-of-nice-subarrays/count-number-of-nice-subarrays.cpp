class Solution {
public:
    int atmostk(vector<int>& nums, int k)
    {
        int s=0, e=0, count=0, ans=0, n=nums.size();
        while(e<n)
        {
            if(nums[e++]%2==1) count++;
            while(count>k)
            {
                if(nums[s++]%2==1) count--;
            }
            ans+=(e-s);
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmostk(nums,k) - atmostk(nums,k-1);
    }
};