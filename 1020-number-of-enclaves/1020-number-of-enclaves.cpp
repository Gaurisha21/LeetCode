class Solution {
public:
    void dfs(int i, int j, vector<vector<int>> &dir, vector<vector<int>> &grid)
    {
        int n=grid.size(), m=grid[0].size();
        grid[i][j]=0;
        for(int d=0; d<dir.size(); d++)
        {
            int r=i+dir[d][0];
            int c=j+dir[d][1];
            if(r>=0 and r<n and c>=0 and c<m and grid[r][c]==1)
                dfs(r,c,dir,grid);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size(), ans=0;
        vector<vector<int>> dir{{0,1},{0,-1},{1,0},{-1,0}};
        
        for(int i=0; i<m; i++)
        {
            if(grid[0][i]==1)
            {
                dfs(0, i, dir, grid);
            }
        } 
        for(int i=0; i<m; i++)
        {
            if(grid[n-1][i]==1)
            {
                dfs(n-1, i, dir, grid);
            }
        } 
        for(int i=0; i<n; i++)
        {
            if(grid[i][0]==1)
            {
                dfs(i, 0, dir, grid);
            }
        } 
        for(int i=0; i<n; i++)
        {
            if(grid[i][m-1]==1)
            {
                dfs(i, m-1, dir, grid);
            }
        }
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
                if(grid[i][j]==1)
                    ans++;
        }
        
        return ans;
    }
};