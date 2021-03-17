class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int count, n=nums.size();
        vector<int> arr;
        for(int i=0; i<n; i++)
        {
            count = 0;
            for(int j=0; j<n; j++)
            {
                if(i!=j)
                {
                    if(nums[j]<nums[i])
                        count++;
                }
            }
            arr.push_back(count);
        }
        return arr;
    }
};