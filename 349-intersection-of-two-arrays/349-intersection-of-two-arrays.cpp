class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> st1, st2;
        vector<int> v1;
        for(int ele:nums1)
            st1.insert(ele);
        for(int ele:nums2)
            st2.insert(ele);
        int n1=st1.size(), n2=st2.size();
        
        if(n1<n2)
        {
            for(int ele: st1)
            {
                if(st2.find(ele)!=st2.end()) v1.push_back(ele);
            }
        }
        else
        {
            for(int ele: st2)
            {
                if(st1.find(ele)!=st1.end()) v1.push_back(ele);
            }
        }
        return v1;
    }
};