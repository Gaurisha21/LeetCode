class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int w, ms = INT_MIN;
        for (int i = 0; i < accounts.size(); i++)
        {
            w = 0; 
            for (int j = 0; j < accounts[i].size(); j++)
            {
                w += accounts[i][j];
            }    
            ms = max(ms, w);
        }
        return ms;
    }
};