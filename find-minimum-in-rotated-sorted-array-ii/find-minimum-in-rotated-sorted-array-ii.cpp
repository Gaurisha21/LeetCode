class Solution {
public:
    int findMin(vector<int>& nums) {
        int n= nums.size();
        int si=0, ei=n-1;
        if(nums[si]<nums[ei]) return nums[si];
        
        
        while(si<ei){
            int mid= (si+ei)/2;
            if(nums[mid]<nums[ei])ei=mid;
            else if(nums[mid]>nums[ei]) si=mid+1;
            else ei--;
            }
        
        return nums[si] ;
    }
};