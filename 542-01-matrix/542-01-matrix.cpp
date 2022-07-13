class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(), m=mat[0].size();
        queue<vector<int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }
        
        vector<vector<int>> dir{{0,1},{1,0},{0,-1},{-1,0}};
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                vector<int> vrt = q.front();
                q.pop();
                for(int d=0; d<dir.size(); d++)
                {
                    int r=vrt[0]+dir[d][0];
                    int c=vrt[1]+dir[d][1];
                    if(r>=0 && r<n && c>=0 && c<m && vis[r][c]==0)
                    {
                        mat[r][c] = mat[vrt[0]][vrt[1]]+1;
                        q.push({r,c});
                        vis[r][c] = 1;
                    }
                }
            }
        }
        
        return mat;
    }
};