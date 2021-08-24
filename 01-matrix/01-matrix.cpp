class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if(n==0 || m==0) return grid;
        vector<vector<int>> dir{{0,1},{0,-1},{1,0},{-1,0}};
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        queue<int> que;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==0)
                {
                    que.push(i*m+j);
                    vis[i][j] = true;
                }
            }
        }
        while(que.size()!=0)
        {
            int size = que.size();
            while(size-->0)
            {
                int idx = que.front();
                que.pop();
                int sr = idx/m, sc = idx%m;
                for(int d = 0; d<dir.size(); d++)
                {
                    int r=sr+dir[d][0];
                    int c=sc+dir[d][1];
                    if(r>=0 && r<n && c>=0 && c<m && !vis[r][c])
                    {
                        grid[r][c] = grid[sr][sc]+1;
                        que.push(r*m+c);
                        vis[r][c] = true;
                    }
                }
            }
        }
        return grid;
    }
};












