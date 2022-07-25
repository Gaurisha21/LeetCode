class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>> dis(n,vector<int>(m,(int)1e9));
        vector<vector<int>> dir{{0,1},{0,-1},{1,0},{-1,0}};
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        // {wsf, r, c}
        pq.push({0,0,0});
        dis[0][0]=0;
        while(!pq.empty())
        {
            vector<int> node = pq.top();
            int wsf=node[0], i=node[1], j=node[2];
            pq.pop();
            if(dis[i][j]<wsf)
                continue;
            if(i==n-1 and j==m-1)
                return wsf;
            for(int d=0; d<dir.size(); d++)
            {
                int r=i+dir[d][0];
                int c=j+dir[d][1];
                if(r>=0 and r<n and c>=0 and c<m)
                {
                    int newWsf = max(wsf,abs(grid[i][j]-grid[r][c]));
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