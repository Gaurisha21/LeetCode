class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int e=0, n=nums.size(), ans=0, sum=0;
        vector<int> rem(k,0);
        rem[0]=1;
        while(e<n)
        {
            sum+=nums[e++];
            int r=(sum%k+k)%k;
            ans+=rem[r];
            rem[r]++;
        }
        return ans;
    }
};