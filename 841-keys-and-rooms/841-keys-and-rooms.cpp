class Solution {
public:
    void dfs(vector<vector<int>> graph, vector<int> &vis, int src)
    {
        vis[src]=1;
        for(int i=0; i<graph[src].size(); i++)
        {
            if(vis[graph[src][i]]==0)
                dfs(graph,vis,graph[src][i]);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size(), comp=0;
        vector<int> vis(n,0);
        for(int i=0; i<n; i++)
        {
            if(vis[i]==0)
            {
                comp++;
                dfs(rooms,vis,i);
            }
        }
        return comp==1 ? true : false;
    }
};