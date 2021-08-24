class Solution {
public:
    void heavyPath(vector<vector<int>>& graph, int src, int dest, vector<bool> &vis,vector<int> &base, vector<vector<int>>& ans)
    {
        if (src == dest)
            ans.push_back(base);

        vis[src] = true;
        for (auto e : graph[src])
        {
            if (!vis[e])
            {
                base.push_back(e);
                heavyPath(graph, e, dest, vis,base, ans);  
                base.pop_back();
            }    
        }
        vis[src] = false;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> ans;
        vector<int> base;
        base.push_back(0);
        vector<bool> vis(n,false);
        heavyPath(graph, 0, n-1, vis, base, ans);
        return ans;
    }
};