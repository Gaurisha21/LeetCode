class Solution {
public:
    bool isPossibleToEat(vector<int> arr, int h, int eatingSpeed)
    {
        int hr=0;
        for(int i=arr.size()-1; i>=0; i--)
        {
            hr+=ceil(arr[i]/(eatingSpeed*1.0));
            if(hr>h) return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& arr, int h) {
        int n=arr.size(), s=1, e=INT_MAX, mid;
        while(s<e)
        {
            mid = (s+(e-s)/2);
            if(!isPossibleToEat(arr,h,mid)) s=mid+1;
            else e=mid;
        }
        return s;
    }
};