class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int ans=0;
        unordered_map<int, int> box;
        for(int i:nums)
            box[i]++;
        for(auto item:box)
            if(item.second==1)
                ans+=item.first;
        return ans;           
    }
};