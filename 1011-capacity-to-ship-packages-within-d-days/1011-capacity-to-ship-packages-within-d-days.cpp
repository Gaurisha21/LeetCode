class Solution {
public:
    bool isPossibleToShip(vector<int>& arr, int d, int mid)
    {
        int cap=0, D=1;
        for(int i=0; i<arr.size(); i++)
        {
            cap+=arr[i];
            if(cap>mid)
            {
                D++;
                cap=arr[i];
            }
            if(D>d) return false;
        }
        return true;
    }
    int shipWithinDays(vector<int>& arr, int d) {
        int n=arr.size(), s=INT_MIN,e=0, mid;
        for(int i=0; i<n; i++)
        {
            s = max(s,arr[i]);
            e += arr[i];
        }
        while(s<e)
        {
            mid=(s+(e-s)/2);
            if(!isPossibleToShip(arr, d, mid)) s=mid+1;
            else e=mid;
        }
        return s;
    }
};