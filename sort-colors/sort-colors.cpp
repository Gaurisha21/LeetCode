class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.size()==1) return;
        int pt1=0, it=0, pt2=nums.size()-1;
        while(it<=pt2)
        {
            if(nums[it]==0)
                swap(nums[pt1++], nums[it++]);
            else if(nums[it]==2)
                swap(nums[it], nums[pt2--]);
            else
                it++;
        }
    }
};