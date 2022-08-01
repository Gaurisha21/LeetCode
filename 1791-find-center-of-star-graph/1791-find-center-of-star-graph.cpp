class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int,int> mp;
        for(vector<int> e : edges)
        {
            int u=e[0], v=e[1];
            if(mp[v]++==1)
                return v;
            if(mp[u]++==1)
                return u;
        }
        return -1;
    }
};