class Solution {
public:
    int combInfCoin(int idx, vector<int> coin, int tar, vector<int> arr, vector<vector<int>> &ans)
    {
        if(tar==0)
        {
            ans.push_back(arr);
            return 1;
        }
        int count=0;
        for(int i=idx; i<coin.size(); i++)
        {
            vector<int> t = arr;
            if(tar-coin[i]>=0)
            {
                arr.push_back(coin[i]);
                count+=combInfCoin(i, coin, tar-coin[i], arr,ans);
                arr = t;
            }
        }
        return count;
    }
    
    vector<vector<int>> combinationSum(vector<int>& coin, int target) {
        vector<vector<int>> ans;
        vector<int> arr;
        int a = combInfCoin(0,coin,target,arr,ans);
        // cout<<a<<endl;
        // for(vector<int> u:ans)
        // {
        //     for(int i:u)
        //         cout<<i<<" ";
        // }
        return ans;
    }
};