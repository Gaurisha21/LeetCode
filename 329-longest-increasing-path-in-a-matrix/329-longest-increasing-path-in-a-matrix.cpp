class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& mat) {
        int n=mat.size(), m=mat[0].size();
        vector<vector<int>> dir{{0,1},{0,-1},{1,0},{-1,0}}, indeg(n,vector<int>(m,0));
        queue<int>q;
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                for(int d=0; d<dir.size(); d++)
                {
                    int r=i+dir[d][0];
                    int c=j+dir[d][1];
                    if(r>=0 and r<n and c>=0 and c<m and mat[r][c]>mat[i][j])
                        indeg[r][c]++;
                }
            }
        }
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(indeg[i][j]==0)
                    q.push(i*m+j);
            }
        }
        
        int level=0;
        
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                int vrt=q.front();
                q.pop();
                int i=vrt/m;
                int j=vrt%m;
                for(int d=0; d<dir.size(); d++)
                {
                    int r=i+dir[d][0];
                    int c=j+dir[d][1];
                    if(r>=0 and r<n and c>=0 and c<m and mat[r][c]>mat[i][j])
                    {
                        if(--indeg[r][c]==0)
                            q.push(r*m+c);
                    }
                }
            }
            level++;
        }
        return level;
    }
};