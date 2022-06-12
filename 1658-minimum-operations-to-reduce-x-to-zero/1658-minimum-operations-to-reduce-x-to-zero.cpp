class Solution {
public:
    int longestSubArr(vector<int> arr, int k)
    {
        unordered_map<int,int> mp;
        int len=INT_MIN, cumsum=0, N=arr.size();
        mp[0]=-1;
        for(int i=0; i<N; i++)
        {
            cumsum+=arr[i];
            if(mp.find(cumsum)==mp.end()) mp[cumsum]=i;
            if(mp.find(cumsum-k)!=mp.end()) 
                len=max(len,i-mp[cumsum-k]);
        }
        return len==INT_MIN?-1:len;
    }
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size(), sum=0;
        for(int ele : nums)
            sum+=ele;
        int i = longestSubArr(nums,sum-x);
        return i!=-1 ? n-i : -1;            
    }
};