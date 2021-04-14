class Solution {
public:
    int num(int n)
    {
        int count=0;
        while(n>0)
        {
            n/=10;
            count++;
        }
        return count;
    }
    int findNumbers(vector<int>& nums) {
        int ans=0;
        for(int i=0; i<nums.size(); i++)
        {
            int d=num(nums[i]);
            if(d%2==0)
                ans++;
        }
        return ans;
    }
};