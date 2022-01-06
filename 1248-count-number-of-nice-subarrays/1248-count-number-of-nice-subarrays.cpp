class Solution {
public:
    bool isOdd(int num)
    {
        if(num%2==1)
            return true;
        return false;
    }
    int atmostK(vector<int>& nums, int k) {
        int n=nums.size(), s=0, e=0, ans=0, count=0;
        while(e<n)
        {
            if(isOdd(nums[e++]))
                count++;
            while(count>k)
            {
                if(isOdd(nums[s++]))
                    count--;
            }
            ans += (e-s);
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmostK(nums,k)-atmostK(nums,k-1);
    }
};