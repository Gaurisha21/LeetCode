class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        long int s = 0, e = arr.size()-1, ans;
        while(s<=e){
            int mid = (s+e)/2;
            if(arr[mid]>arr[mid+1] and arr[mid]>arr[mid-1])
            {
                ans = mid; 
                break;
            }
            else if(arr[mid]>arr[mid+1])
            {
                e = mid - 1;
            }
            else if(arr[mid]<arr[mid+1])
            {
                s = mid + 1;
            }
        }
        return ans;        
    }
};