class Solution {
public:
    vector<vector<int>> twoSum(vector<int> arr, int s, int e, int k)
    {
        int n=(e-s+1);
        vector<vector<int>> ans;
        while(s<e)
        {
            // fill(paiR.begin(), paiR.end(),0);
            if(arr[s]+arr[e]==k)
            {
                ans.push_back({arr[s],arr[e]});
                s++;
                e--;
                while(arr[s]==arr[s-1] and s<e) s++;
                while(arr[e]==arr[e+1] and s<e) e--;
            }
            else if(arr[s]+arr[e]>k)
            {
                // while(arr[e]==arr[e-1] and e!=0) e--;
                e--;
            }
            else
            {
                // while(arr[s]==arr[s+1] and s!=n-1) s++;
                s++;
            }
        }
        return ans;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size(),j,k, target = 0;
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0; i<n-1;)
        {
            vector<vector<int>> pr = twoSum(nums,i+1,n-1,(target-nums[i]));
            for(vector<int> p : pr)
            {
                j=p[0], k=p[1];
                // cout<<j<<" "<<i<<endl;
                ans.push_back({nums[i],j,k});
            }
            i++;
            while(i<n-1 and nums[i]==nums[i-1]) i++;
        }
        return ans;
    }
};