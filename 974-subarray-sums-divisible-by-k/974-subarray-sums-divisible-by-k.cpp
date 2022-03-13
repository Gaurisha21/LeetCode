class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        map[0]=1;
        int e=0, n=nums.size(), sum=0, ans=0;
        while(e<n)
        {
            sum += nums[e];
            int rem = (sum%k+k)%k;;
            if(map.find(rem)!=map.end()) 
                ans += map[rem];
            map[rem]++;            
            e++;
        }
        return ans;
    }
};