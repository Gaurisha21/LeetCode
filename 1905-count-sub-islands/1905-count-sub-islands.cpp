class Solution {
public:
    bool dfs(vector<vector<int>> &grid1, vector<vector<int>> &grid2, int i, int j, vector<vector<int>> dir)
    {
        bool res = true;
        int n=grid1.size(), m=grid1[0].size();
        grid2[i][j]=0;
        for(int d=0; d<dir.size(); d++)
        {
            int r=i+dir[d][0];
            int c=j+dir[d][1];
            if(r>=0 and r<n and c>=0 and c<m and grid2[r][c]==1)
                res = dfs(grid1, grid2, r,c,dir) && res;
        }
        return (res && (grid1[i][j]==1));
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid1.size(), m=grid1[0].size(), count=0;
        int flag = 0;
        vector<vector<int>> dir{{0,1},{0,-1},{1,0},{-1,0}};
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid2[i][j]==1)
                    flag += dfs(grid1, grid2, i, j, dir) ? 1 : 0;
            }
        }
        return flag;
    }
};