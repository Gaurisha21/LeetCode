class Solution {
public:
    int findMin(vector<int>& nums) {
        int s=0, e=nums.size()-1, mini=INT_MAX;
        while(s<=e)
        {
            int mid=(s+e)/2;
            if(nums[s]<=nums[mid])
            { 
                mini=min(mini, nums[s]);
                s=mid+1;
            }
            else
            {
                mini=min(mini, nums[mid]);
                e=mid-1;
            }
        }
        return mini;
    }
};