class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int> st1, st2;
        vector<int> v1,v2;
        for(int ele:nums1)
            st1.insert(ele);
        for(int ele:nums2)
            st2.insert(ele);
        for(int ele: st1)
        {
            if(st2.find(ele)==st2.end()) v1.push_back(ele);
        }
        for(int ele: st2)
        {
            if(st1.find(ele)==st1.end()) v2.push_back(ele);
        }
        return {v1,v2};
    }
};