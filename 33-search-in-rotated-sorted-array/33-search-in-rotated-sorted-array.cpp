class Solution {
public:
    int search(vector<int>& nums, int k) {
        int n=nums.size(), s=0, e=n-1, mid;
        while(s<=e)
        {
            mid = s+((e-s)/2);
            if(nums[mid]==k) return mid;
            else if(nums[s]<=nums[mid])
            {
                if(nums[s]<=k and k<nums[mid]) e=mid-1;
                else s=mid+1;
            }
            else if(nums[e]>nums[mid])
            {
                if(nums[mid]<k and k<=nums[e]) s=mid+1;
                else e=mid-1;
            }
            // cout<<s<<" "<<mid<<" "<<e<<endl;
        }
        return -1;
    }
};