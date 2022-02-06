class Solution {
public:
    static bool comp(string a, string b)
    {
        if(a.size()!=b.size()) return a.size()<b.size();
        return a<b;
    }
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(),nums.end(), comp);   
        int n=nums.size();
        // for(string s:nums)
        //     cout<<s<<" ";
        return nums[n-k];
    }
};