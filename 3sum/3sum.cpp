class Solution {
public:
    vector<vector<int>> twoSum(vector<int> &arr, int target, int si, int ei)
    {
        vector<vector<int>> ans;
        while (si < ei)
        {
            int sum = arr[si] + arr[ei];
            if (sum == target)
            {
                ans.push_back({arr[si], arr[ei]});

                si++;
                ei--;
                while (si < ei && arr[si] == arr[si - 1])
                    si++;
                while (si < ei && arr[ei] == arr[ei + 1])
                    ei--;
            }
            else if (sum < target)
                si++;
            else
                ei--;
        }

        return ans;
    }

    void prepareAns(vector<vector<int>> &ans, vector<vector<int>> &smallAns, int fixEle)
    {

        for (vector<int> &arr : smallAns)
        {
            vector<int> ar;
            ar.push_back(fixEle);
            for (int ele : arr)
                ar.push_back(ele);
            ans.push_back(ar);
        }
    }

    vector<vector<int>> threeSum(vector<int> &arr, int target, int si, int ei)
    {
        vector<vector<int>> ans;
        for (int i = si; i < ei;)
        {
            vector<vector<int>> smallAns = twoSum(arr, target - arr[i], i + 1, ei);
            prepareAns(ans, smallAns, arr[i]);
            i++;
            while (i < ei && arr[i] == arr[i - 1])
                i++;
        }
        return ans;
    }
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        return threeSum(nums, 0, 0, nums.size()-1);
    }
};