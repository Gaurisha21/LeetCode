class Solution {
public:
    int perm(vector<int> nums, int idx, vector<vector<int>> &ans, vector<int> &arr)
    {
        int n=nums.size();
        if(idx==n)
        {
            ans.push_back(arr);
            return 1;
        }
        int count=0;
        int prev = -11;
        for(int i=0; i<n; i++)
        {
            if(nums[i]!=-11 and nums[i]!=prev)
            {
                prev = nums[i];
                vector<int> t=arr;
                int temp=nums[i];
                nums[i] = -11;
                arr.push_back(temp);
                count+=perm(nums,idx+1,ans,arr);
                arr=t;
                nums[i] = temp;
            }
        }
        return count;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> arr;
        sort(nums.begin(), nums.end());
        int s=perm(nums,0,ans,arr);
        // cout<<s;
        return ans;
    }
};