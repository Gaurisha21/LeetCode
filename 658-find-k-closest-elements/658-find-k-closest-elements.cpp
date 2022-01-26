class Solution {
public:
    int insertPos(vector<int>& arr, int x)
    {
        int mid, s=0, n=arr.size(), e=n-1;
        while(s<=e)
        {
            mid = (s+(e-s)/2);
            if(arr[mid]>x) e=mid-1;
            else s=mid+1;
        }
        return s;
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int ps = insertPos(arr,x), n=arr.size();
        int l=max(0,ps-k), r=min(n-1,ps+k);
        vector<int> ans;
        if(x<=arr[0])
        {
            for(int i=0; i<k; i++)
                ans.push_back(arr[i]);
            return ans;
        }
        else if(x>=arr[n-1])
        {
            for(int i=n-k;i<n;i++)
                ans.push_back(arr[i]);
            return ans;
        }
        else 
        {
            while(r-l+1>k)
            {
                if(x-arr[l]>arr[r]-x) l++;
                else r--;
            }
        }
        for(int i=l; i<=r; i++)
            ans.push_back(arr[i]);
        return ans;
    }
};