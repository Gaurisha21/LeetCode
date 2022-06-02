class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& mat) {
        int R = mat.size(), C = mat[0].size();
        vector<vector<int>>ans (C,(vector(R,0)));
        for (int r = 0; r < R; r++)
            for (int c = 0; c < C; c++) {
                ans[c][r] = mat[r][c];
            }
        return ans;
    }
};