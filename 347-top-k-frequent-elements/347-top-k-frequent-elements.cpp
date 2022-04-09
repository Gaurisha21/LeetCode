class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        vector<int> ans;
        priority_queue<vector<int>> pq;
        for(int ele:nums)
            map[ele]++;
        for(auto ele:map)
            pq.push({ele.second,ele.first});
        // while(!pq.empty())
        // {
        //     vector<int> a = pq.top();
        //     cout<<a[1]<<" "<<a[0]<<endl;
        //     pq.pop();
        // }
        for(int i=0; i<k; i++)
        {
            vector<int> a = pq.top();
            ans.push_back(a[1]);
            pq.pop();
        }
        return ans;
    }
};