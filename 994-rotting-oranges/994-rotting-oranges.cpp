class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size(), orangeCount=0, time=0;
        queue<vector<int>> q;
        vector<vector<int>> dir{{0,1},{1,0},{0,-1},{-1,0}};
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==1)
                    orangeCount++;
                else if(grid[i][j]==2)
                    q.push({i,j});
            }
        }
        if(orangeCount==0) return 0;
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                vector<int> vrt = q.front();
                q.pop();
                for(int d=0; d<dir.size(); d++)
                {
                    int r=vrt[0]+dir[d][0];
                    int c=vrt[1]+dir[d][1];
                    if(r>=0 and r<n and c>=0 and c<m and grid[r][c]==1)
                    {
                        grid[r][c]=2;
                        q.push({r,c});
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