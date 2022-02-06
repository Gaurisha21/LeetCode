class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<vector<int>> pq, m;
        map<int,int> mp;
        vector<int> ans;
        for(int ele:nums)
        {
            mp[ele]++;
        }
        // for(auto ele:mp)
        //     cout<<ele.second<<" "<<ele.first<<endl;
        for(auto ele:mp)
        {
            pq.push({ele.second,ele.first});
            m.push({ele.second,ele.first});
        }
        // while(!m.empty())
        // {
        //     vector<int>o = m.top();
        //     cout<<o[1]<<" "<<o[0]<<endl;
        //     m.pop();
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