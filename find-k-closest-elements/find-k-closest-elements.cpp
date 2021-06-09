class Solution {
public:
    int insertPostion(vector<int> arr, int x)
    {
        int s=0, n=arr.size(), e=n-1;
        while(s<=e)
        {
            int mid=s+((e-s)/2);
            if(arr[mid]<=x) s=mid+1;
            else e=mid-1;
        }
        return s;
    }
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int ind=insertPostion(arr, x);
        
        int n=arr.size();
        
        int lr=max(0,ind-k), rr=min(n-1, ind+k);
        
        vector<int> ans;
        
        if (x <= arr[0])
        {
            for(int i=0; i<k; i++)
                ans.push_back(arr[i]);
            return ans;
        }
        else if (x >= arr[n - 1])
        {
            for(int i=n-k; i<n; i++)
                ans.push_back(arr[i]);
            return ans;
        }
        
        while((rr-lr+1)>k)
        {
            if((x-arr[lr])>(arr[rr]-x)) lr++;
            else rr--;
        }
        
        for(int i=lr; i<=rr; i++)
            ans.push_back(arr[i]);
        return ans;
    }
};