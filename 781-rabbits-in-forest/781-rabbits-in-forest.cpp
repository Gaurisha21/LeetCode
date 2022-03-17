class Solution {
public:
    int numRabbits(vector<int>& arr) {
        unordered_map<int,int> map;
        int ans=0;
        for(int ele: arr)
        {
            if(map[ele]==0)
                ans += (ele + 1);
            map[ele]++;

            if (map[ele] == ele + 1)
                map[ele] = 0;
        }
        return ans;
    }
};