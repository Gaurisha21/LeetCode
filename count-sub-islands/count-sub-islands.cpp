class Solution {
public:
    vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
    void dfs(int i, int j, vector<vector<int>> &dir, vector<vector<int>>& grid2)
    {
        int n = grid2.size(), m=grid2[0].size();
        grid2[i][j] = 0;
        for(int d=0; d<dir.size(); d++) {
            int r = i + dir[d][0];
            int c = j + dir[d][1];

            if (r >= 0 && c >= 0 && r < n && c < m && grid2[r][c] == 1)  {
                dfs(r, c, dir, grid2);
            }
        }    
    }
    
    int numIslands(vector<vector<int>> &grid)
    {
        vector<vector<int>> dir{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        int n = grid.size(), m = grid[0].size(), components = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    components++;
                    dfs(i, j, dir, grid);
                }
            }
        }

        return components;
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size(), m=grid1[0].size();
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid1[i][j]==0 && grid2[i][j]==1)
                {
                    dfs(i, j, dir, grid2);
                }
            }
        }
        return numIslands(grid2);
    }
};

