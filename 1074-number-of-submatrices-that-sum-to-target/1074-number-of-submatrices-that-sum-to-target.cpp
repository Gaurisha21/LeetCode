class Solution {
public:
    int findSubArraySum(vector<int> arr, int k)
    {
        unordered_map<int,int> mp;
        int ans=0, cumsum=0, N=arr.size();
        for(int i=0; i<N; i++)
        {
            cumsum+=arr[i];
            if(cumsum==k) ans++;
            if(mp.find(cumsum-k)!=mp.end()) 
                ans+=mp[cumsum-k];
            mp[cumsum]++;
        }
        return ans;
    }
    int numSubmatrixSumTarget(vector<vector<int>>& arr, int k) {
        int n=arr.size(), m=arr[0].size(), mx=0;
        for(int fr=0; fr<n; fr++)
        {
            vector<int> ans(m,0);
            for(int r=fr; r<n; r++)
            {
                for(int c=0; c<m; c++)
                    ans[c]+=arr[r][c];
                mx += findSubArraySum(ans,k);
            }
        }
        return mx;
    }
};