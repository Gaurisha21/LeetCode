class Solution {
public:
    int xorOperation(int n, int start) {
        vector<int> nums;
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            int x = start + (2*i);
            nums.push_back(x);
        }
        for(int i=0; i<n; i++)
        {
            ans ^= nums[i];
        }
        return ans;
    }
};