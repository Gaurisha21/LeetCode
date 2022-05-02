class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int p=-1, s=0, n=nums.size();
        while(s<n)
        {
            if(nums[s]%2==0)
                swap(nums[++p],nums[s]);
            s++;
        }
        return nums;
    }
};