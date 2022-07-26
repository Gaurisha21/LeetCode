class Solution {
public:
    int maxProd(int n, int m, vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &dp)
    {
        if(n==0 || m==0)
            return dp[n][m]= -(int)1e8;
        if(dp[n][m]!=-(int)1e9)
            return dp[n][m];
        
        int val = nums1[n-1]*nums2[m-1];
        int a = maxProd(n-1,m-1,nums1,nums2,dp)+val;
        int b = maxProd(n-1,m,nums1,nums2,dp);
        int c = maxProd(n,m-1,nums1,nums2,dp);
        
        return dp[n][m]=max(max(a,b),max(c,val));
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(), m=nums2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-(int)1e9));
        return maxProd(n,m,nums1,nums2,dp);
    }
};