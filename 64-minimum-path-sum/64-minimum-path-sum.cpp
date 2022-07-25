class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>> dis(n,vector<int> (m,(int)1e9)), dir{{0,1},{1,0}};
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        
        pq.push({grid[0][0],0,0});
        dis[0][0]=grid[0][0];
        
        while(!pq.empty())
        {
            vector<int> node = pq.top();
            pq.pop();
            int wsf=node[0], i=node[1], j=node[2];
            if(dis[i][j]<wsf)
                continue;
            if(i==n-1 and j==m-1)
                return wsf;//+grid[i][j];
            for(int d=0; d<dir.size(); d++)
            {
                int r=i+dir[d][0];
                int c=j+dir[d][1];
                if(r>=0 and r<n and c>=0 and c<m)
                {
                    int newWsf = wsf+grid[r][c];
                    if(newWsf<dis[r][c])
                    {
                        dis[r][c]=newWsf;
                        pq.push({dis[r][c],r,c});
                    }
                }
            }
        }
        return -1;
    }
};