class Solution {
public:
    int numIslands(vector<vector<int>>& grid, int i, int j, vector<vector<int>> &dir){
        grid[i][j] = 0;
        int m = grid.size(), n = grid[0].size(), size = 0;
        for(int d=0; d<dir.size(); d++)
        {
            int x = i + dir[d][0];
            int y = j + dir[d][1];
            if(x>=0 && x<m && y>=0 && y<n && grid[x][y] == 1)
                size+=numIslands(grid, x, y, dir);
        }
        return size + 1;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), maxArea = 0;
        vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 1)
                {
                    int area = numIslands(grid, i, j, dir);                        
                    maxArea = max(area, maxArea);
                }
            }
        }
       
        return maxArea;   
    }
};