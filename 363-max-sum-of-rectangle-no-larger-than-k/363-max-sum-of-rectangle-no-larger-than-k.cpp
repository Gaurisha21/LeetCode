class Solution {
public:
    int sumK(vector<int> arr, int k)
    {
        set<int> cumSum;
        cumSum.insert(0);
        int sum=0, maxS=INT_MIN, n=arr.size();
        for(int i=0; i<n; i++)
        {
            sum+=arr[i];
             set<int>::iterator it = cumSum.lower_bound(sum-k);
            if(it!=cumSum.end())
                maxS = max(maxS, sum-*it);
            cumSum.insert(sum);
        }
        return maxS;
    }
    int maxSumSubmatrix(vector<vector<int>>& nums, int k) {
        int n=nums.size(), m=nums[0].size(), ans = INT_MIN;
        vector<int>res(m,0);
        for(int firstRow=0; firstRow<n; firstRow++)
        {
            fill(res.begin(),res.end(),0);
            for(int row=firstRow; row<n; row++)
            {
                for(int col=0; col<m; col++)
                    res[col]+=nums[row][col];
                // for(int j=0; j<m; j++)
                //     cout<<res[j]<<" ";
                // cout<<endl;
                int mSum = sumK(res,k);
                // cout<<mSum<<endl;
                ans = max(ans,mSum);
            }
        }
        return ans;
    }
};