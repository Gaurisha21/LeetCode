class Solution {
public:
    int path(int sr, int sc, vector<vector<int>> grid, vector<vector<int>> dir, int zero)
    {
        int n=grid.size(), m=grid[0].size();
        if(grid[sr][sc]==2)
        {
            return zero==-1 ? 1 : 0;
        }
        int count=0;
        int temp = grid[sr][sc];
        grid[sr][sc]=-1;
        zero--;
        for(int d=0; d<dir.size(); d++)
        {
            int r=sr+dir[d][0];
            int c=sc+dir[d][1];
            if(r>=0 and c>=0 and r<n and c<m and grid[r][c]!=-1)
                count+=path(r,c,grid,dir,zero);
        }
        grid[sr][sc]=temp;
        zero++;
        return count;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        vector<vector<int>> dir{{0,1},{1,0},{-1,0},{0,-1}};
        int n=grid.size(), m=grid[0].size();
        int ans=0,sr,sc,zero=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==1)
                {
                    sr=i;
                    sc=j;
                }
                else if(grid[i][j]==0) zero++;
            }
        }
        // cout<<zero<<" ";
        ans = path(sr,sc,grid,dir,zero);
        return ans;
    }
};