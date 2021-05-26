class Solution {
public:
    int firstocc(vector<int>& nums, int target)
    {
        if(nums.size()==1) return nums[0]==target ? 0 : -1;
        if(nums.size()<1) return -1;
        int s=0, e=nums.size()-1, mid;
        while(s<=e)
        {
            mid=s+((e-s)/2);
            if(nums[mid]==target)
            {
                if(mid==0) return mid;
                if(nums[mid] != nums[mid-1] ) return mid;
                else if(nums[mid] == nums[mid-1]) e=mid - 1;
            }
            else if(nums[mid]>target) e = mid-1;
            else if(nums[mid]<target) s = mid+1;
        }
        return -1;
    }
    int lastocc(vector<int>& nums, int target)
    {
        if(nums.size()==1) return nums[0]==target ? 0 : -1;
        if(nums.size()<1) return -1;
        int s=0, e=nums.size()-1, mid;
        while(s<=e)
        {
            mid=s+((e-s)/2);
            if(nums[mid]==target)
            {
                if(mid==nums.size()-1) return mid;
                if(nums[mid] != nums[mid+1] ) return mid;
                else if(nums[mid] == nums[mid+1]) s=mid + 1;
            }
            else if(nums[mid]>target) e = mid-1;
            else if(nums[mid]<target) s = mid+1;
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int a=firstocc(nums, target);
        int b=lastocc(nums, target);
        ans.push_back(a);
        ans.push_back(b);
        return ans;
    }
};