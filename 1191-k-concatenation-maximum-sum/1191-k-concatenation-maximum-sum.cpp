class Solution {
public:
    int mod = (int)1e9+7;
    int kadane(vector<int> arr, int k)
    {
        long gsum=0, csum=0;
        int n=arr.size();
        for(int i=0; i<n*k; i++)
        {
            csum+=arr[i%n];
            gsum = max(gsum,csum);
            if(csum<0)
                csum=0;
        }
        return (int)gsum%mod;
    }
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        if(k==1 || k==2 || k==3)
            return (int)kadane(arr,k);
        long s2s3x=0, s2s3=0, x=0;
        s2s3x = kadane(arr,3);
        s2s3 = kadane(arr,2);
        x = s2s3x-s2s3;
        return (int)((s2s3 + (k-2)*x)%mod);
    }
};