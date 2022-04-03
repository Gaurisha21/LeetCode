class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size(), i, j;
        for(i=n-1; i>0; i--)
        {
            if(nums[i]>nums[i-1]) break;
        }
        // cout<<i;
        if(i<=0)
        {
            sort(nums.begin(), nums.end());
            return;
        }
        for(j=n-1; j>=0; j--)
        {
            if(nums[j]>nums[i-1])
            {
                swap(nums[i-1],nums[j]);
                sort(nums.begin()+i,nums.end());
                return;
            }
        }
    }
};