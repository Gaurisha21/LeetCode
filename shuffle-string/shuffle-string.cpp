class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
    int n = indices.size();
    char ans[n]; 
    for(int i=0; i<n; i++)
    {
        ans[indices[i]] = s[i];
    }
    string answ;
    for(int i = 0; i < n; i++){
        answ += ans[i];
    }
    return answ;
    }
};