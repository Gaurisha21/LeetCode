class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<int>> &dir, int i, int j)
    {
        grid[i][j]='&';
        int n=grid.size(), m=grid[0].size();
        for(int d=0; d<dir.size(); d++)
        {
            int r=i+dir[d][0];
            int c=j+dir[d][1];
            if(r>=0 and r<n and c>=0 and c<m and grid[r][c]=='O')
                dfs(grid,dir,r,c);
            
        }
    }
    void solve(vector<vector<char>>& grid) {
        vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
        int n=grid.size(), m=grid[0].size();
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(i==0 || j==0 || i==n-1 || j==m-1)
                {
                    if(grid[i][j]=='O')
                        dfs(grid, dir, i,j);
                }
            }
        }
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]=='O')
                    grid[i][j]='X';
                else if(grid[i][j]=='&')
                    grid[i][j]='O';
            }
        }
    }
};