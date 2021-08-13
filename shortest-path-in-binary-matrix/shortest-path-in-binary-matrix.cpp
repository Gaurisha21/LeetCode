class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        if(n==0 || m==0)
            return 0;
        if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1)
            return -1;
        vector<vector<int>>dir = {{ 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 }, { 1, 1 }, { -1, 1 }, { 1, -1 }, { -1, -1 }};
        int time = 1;
        queue<int> que;
        que.push(0);
        while(que.size()!=0)
        {
            int size = que.size();
            while(size-->0)
            {
                int vrt = que.front();
                que.pop();
                int sr = vrt/m, sc=vrt%m;
                if(sr == n-1 && sc == m-1) return time;
                for(int d=0; d<dir.size(); d++)
                {
                    int r=sr+dir[d][0];    
                    int c=sc+dir[d][1];
                    if(r>=0 && r<n && c>=0 && c<m && grid[r][c]==0)
                    {
                        grid[r][c]=1;
                        que.push(r*m+c);
                    }
                }
            }
            time++;
        }
        return -1;
    }
};