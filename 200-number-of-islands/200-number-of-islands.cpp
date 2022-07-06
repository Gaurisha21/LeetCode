class Solution {
public:
    void gcc(vector<vector<char>> &grid, int i, int j, vector<vector<int>> &dir)
    {
        int n=grid.size(), m=grid[0].size();
        grid[i][j]='0';
        for(int d=0; d<dir.size(); d++)
        {
            int r=i+dir[d][0];
            int c=j+dir[d][1];
            if(r>=0 and r<n and c>=0 and c<m and grid[r][c]=='1')
                gcc(grid,r,c,dir);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        int comp=0;
        int n=grid.size(), m=grid[0].size();
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]=='1')
                {
                    comp++;
                    gcc(grid,i,j,dir);
                }
            }
        }
        return comp;
    }
};