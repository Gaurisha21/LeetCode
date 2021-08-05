class Solution {
public:
    void numIslands(vector<vector<char>>& grid, int i, int j, vector<vector<int>> &dir){
        grid[i][j] = '0';
        int m = grid.size(), n = grid[0].size(), comp = 0;
        for(int d=0; d<dir.size(); d++)
        {
            int x = i + dir[d][0];
            int y = j + dir[d][1];
            if(x>=0 && x<m && y>=0 && y<n && grid[x][y] == '1')
                numIslands(grid, x, y, dir);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), comp = 0;
        vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] =='1')
                {
                    comp++;
                    numIslands(grid, i, j, dir);                        
                }
            }
        }
       
        return comp;
    }
};