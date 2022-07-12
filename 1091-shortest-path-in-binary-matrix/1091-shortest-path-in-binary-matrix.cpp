class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size(), ans;
        if(n==1 and grid[0][0]==0)
            return 1;
        if(grid[0][0]==1 || grid[n-1][n-1]==1)
            return -1;
        vector<vector<int>> dir {{0,1},{1,0},{0,-1},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1}};
        queue<vector<int>> q;
        q.push({0,0,1});
        grid[0][0]=1;
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                vector<int> vrt = q.front();
                q.pop();
                for(int d=0; d<dir.size(); d++)
                {
                    int r = vrt[0]+dir[d][0];
                    int c = vrt[1]+dir[d][1];
                    if(r==n-1 and c==n-1)
                        return vrt[2]+1;
                    else if(r>=0 and r<n and c>=0 and c<n and grid[r][c]==0)
                    {
                        grid[r][c]=1;
                        q.push({r,c,vrt[2]+1});
                    }
                }
            }
        }
        return -1;
    }
};