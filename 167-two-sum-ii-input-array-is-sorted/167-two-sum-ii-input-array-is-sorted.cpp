class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int k) {
        vector<int> ans;
        int s=0, e=arr.size()-1;
        while(s<e)
        {
            int sum=arr[s]+arr[e];
            if(sum==k) 
            {
                ans = {s+1,e+1};
                break;
            }
            else if(sum>k) e--;
            else s++;
        }
        return ans;
    }
};