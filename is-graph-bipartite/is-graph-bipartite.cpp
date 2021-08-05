class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph, int src, vector<int> &vis)
    {
        queue<int> que;
        que.push(src);
        int color = 0;
        bool isCycle = false;
        while(que.size() != 0)
        {
            int size = que.size();
            while(size-->0)
            {
                int rvtx = que.front();
                que.pop();
                if(vis[rvtx] != -1)
                {
                    isCycle = true;
                    if(vis[rvtx] != color)
                        return false;
                    continue;
                }
                vis[rvtx] = color;
                for(int v : graph[rvtx])
                {
                    if(vis[v] == -1)
                        que.push(v);
                }
            }
            color = (color+1)%2;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,-1);
        bool res = true;
        for (int i = 0; i < n; i++)
        {
            if (vis[i] == -1)
                res = res && isBipartite(graph, i, vis);
        }

        return res;
    }
};