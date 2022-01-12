class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        int len=0, cumsum=0, n=arr.size();
        for(int i=0; i<n; i++)
        {
            cumsum+=arr[i];
            if(cumsum==k) len++;
            if(mp.find(cumsum-k)!=mp.end()) 
                len+=mp[cumsum-k];
            mp[cumsum]++;
        }
        return len;
    }
};