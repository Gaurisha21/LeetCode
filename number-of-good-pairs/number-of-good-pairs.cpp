class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size(), gp=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i<j)
                {
                    if(nums[i]==nums[j])
                        gp++;
                }
            }
        }
        return gp;
    }
};