class Solution {
public:
    int arraySign(vector<int>& nums) {
    int pro=1;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]>0)
        {
            nums[i]=1;
            pro*=nums[i];
        }
        else if(nums[i]<0)
        {
            nums[i]=-1;
            pro*=nums[i];
        }
        else{
            nums[i]=0;
            pro*=nums[i];
        }
    }
        return pro;
    }
};