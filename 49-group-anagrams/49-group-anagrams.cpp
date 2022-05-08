class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<int>> map;
        int n=strs.size();
        for(int i=0; i<n; i++)
        {
            string w=strs[i];
            sort(w.begin(), w.end());
            map[w].push_back(i);
        }
        for(auto it: map)
        {
            vector<string> small;
            for(int i=0; i<it.second.size(); i++)
                small.push_back(strs[it.second[i]]);
            ans.push_back(small);
        }
        return ans;
    }
};