class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> map;
        int ans=0;
        for(auto i : nums1)
        {
            for(auto j : nums2)
                map[i+j]++;
        }
        for(auto k : nums3)
        {
            for(auto l : nums4)
                ans+=map[-1*(k+l)];
        }
        return ans;
    }
};