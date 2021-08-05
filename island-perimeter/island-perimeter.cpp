class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        int n = grid.size(), m = grid[0].size(), count = 0, nbrCnt = 0;
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<m; j++)
            {
                if(grid[i][j] == 1)
                {
                    count++;
                    for(int d = 0; d<dir.size(); d++)
                    {
                        int r = i + dir[d][0];
                        int c = j + dir[d][1];
                        if(r>=0 && r<n && c>=0 && c<m && grid[r][c] == 1)
                            nbrCnt++;
                    }
                }
            }
        }
        return 4*count - nbrCnt; 
    }
};