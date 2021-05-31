class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        map<int, int> sum1;
        for(auto it : nums1)
        {
            for(auto it1 : nums2)
            {
                sum1[it+it1]++;
            }
        }
        int ans=0;
        for(auto it : nums3)
        {
            for(auto it1 : nums4)
            {
                ans += sum1[-(it+it1)];
            }
        }
        return ans;
    }
};