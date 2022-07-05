class Solution {
public:
    bool ans = false;
    void dfs(vector<vector<int>> &graph, int src, int dest, vector<int> &vis)
    {
        vis[src] = 1;
        if(src==dest)
        {
            ans = true;
            return;
        }
        for(auto it : graph[src])
        {
            if(vis[it]==0)
                dfs(graph,it,dest,vis);
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>graph(n);
        vector<int>vis(n,0);
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        dfs(graph, source, destination, vis);
        return ans;
    }
};