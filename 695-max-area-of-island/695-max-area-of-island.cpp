class Solution {
public:
    
    vector<int> par, size;
    
    int findParent(int u)
    {
        return par[u]==u ? u : (par[u]=findParent(par[u]));
    }
        
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size(), maxAns = 0;
        for(int i=0; i<n*m; i++)
        {
            par.push_back(i);
            size.push_back(1);
        }
        
        vector<vector<int>> dir{{0,1},{0,-1},{1,0},{-1,0}};
        
        for(int i=0; i<n ;i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==1)
                {
                    int p1 = findParent(i*m+j);
                    for(int d=0;d<dir.size(); d++)
                    {
                        int r=i+dir[d][0];
                        int c=j+dir[d][1];
                        if(r>=0 and r<n and c>=0 and c<m and grid[r][c]==1)
                        {
                            int p2 = findParent(r*m+c);
                            if(p1!=p2)
                            {
                                par[p2]=p1;
                                size[p1]+=size[p2];
                            }
                        }
                    }
                    maxAns = max(maxAns,size[p1]);
                }
            }
        }
        return maxAns;
    }
};