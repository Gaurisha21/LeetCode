class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int t) {
        float winsum=0;
        int ans=0, s=0, e=k, n=arr.size(), sum=k*t;
        for(int i=0; i<k; i++)
            winsum += (float)arr[i];
        if(winsum>=sum)
            ans++;
        while(e<n)
        {
            winsum = winsum - arr[s] + arr[e];
            if(winsum>=sum) ans++;
            s++;
            e++;
        }
        return ans;
    }
};