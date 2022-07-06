class Solution {
public:
    int gcc(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dir)
    {
        int n=grid.size(), m=grid[0].size(), size = 0;
        grid[i][j]=0;
        for(int d=0; d<dir.size(); d++)
        {
            int r=i+dir[d][0];
            int c=j+dir[d][1];
            if(r>=0 and r<n and c>=0 and c<m and grid[r][c]==1){
                size += gcc(grid,r,c,dir);
            }
        }
        return size+1;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        int comp=0;
        int n=grid.size(), m=grid[0].size(), area = 0, maxArea = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==1)
                {
                    comp++;
                    area = gcc(grid,i,j,dir);
                    maxArea = max(area,maxArea);
                }
            }
        }
        return maxArea;
    }
};