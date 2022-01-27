class Solution {
public:
    int insertPos(vector<int> arr, int x)
    {
        int n=arr.size(), s=0, e=n-1, mid;
        while(s<=e)
        {
            mid = (s+(e-s)/2);
            if(arr[mid]>x) e=mid-1;
            else s=mid+1;
        }
        return s-1>=0 and arr[s-1]==x ? s-1 : s;
    }
    int lengthOfLIS(vector<int>& arr) {
        int n=arr.size();
        if(n<=1) return n;
        vector<int> ans;
        // ans.push_back(arr[0]);
        for(int ele : arr)
        {
            int ps = insertPos(ans,ele);
            if(ps==ans.size()) ans.push_back(ele);
            else ans[ps] = ele;
        }
        return ans.size();
    }
};