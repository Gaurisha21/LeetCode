class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int orangeCount = 0, time = 0, n = grid.size(), m = grid[0].size();
        queue<int> que;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==2)
                    que.push(i*m+j);
                else if(grid[i][j]==1)
                    orangeCount++;
            }
        }
        if (orangeCount == 0)
            return 0;
        vector<vector<int>>dir = {{0,1},{0,-1},{1,0},{-1,0}};
        while(que.size()!=0)
        {
            int size = que.size();
            while(size-->0)
            {
                int vrt = que.front();
                que.pop();
                int sr = vrt/m, sc=vrt%m;
                for(int d=0; d<dir.size(); d++)
                {
                    int r=sr+dir[d][0];    
                    int c=sc+dir[d][1];
                    if(r>=0 && r<n && c>=0 && c<m && grid[r][c]==1)
                    {
                        grid[r][c]=2;
                        que.push(r*m+c);
                        orangeCount--;
                        if(orangeCount == 0) return time+1;
                    }
                }
            }
            time++;
        }
        return -1;
    }
};