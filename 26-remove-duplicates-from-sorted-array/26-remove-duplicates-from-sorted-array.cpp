class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0, j=1, n=nums.size();
        if(n<=1) return n;
        while(j<n)
        {
            if(nums[i]!=nums[j])
            { 
                i++;
                nums[i] = nums[j];
            }
            j++;
        }
        // for(int ele : nums)
        //     cout<<ele<<" ";
        return i+1;
    }
};