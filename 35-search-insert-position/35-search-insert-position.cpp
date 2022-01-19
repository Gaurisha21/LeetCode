class Solution {
public:
    int search(vector<int> arr, int k)
    {
        int s=0, e = arr.size()-1, mid;
        while(s<=e)
        {
            mid = s+((e-s)/2);
            if(arr[mid]==k) return mid;
            else if(arr[mid]<k) s=mid+1;
            else if(arr[mid]>k) e=mid-1;
        }
        return s;
        
    }
    int searchInsert(vector<int>& nums, int target) {
        return search(nums, target);
        
    }
};