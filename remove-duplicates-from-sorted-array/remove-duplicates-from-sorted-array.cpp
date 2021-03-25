class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto it = unique(nums.begin(), nums.end());
        nums.resize(distance(nums.begin(), it));
        return nums.size();
    }
};