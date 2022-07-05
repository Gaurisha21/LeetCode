class Solution {
public:
    int dfs(vector<vector<int>> &graph, vector<int> &vis, int src, int dest, vector<int> &smallAns, vector<vector<int>> &ans)
    {
        if(src==dest)
        {
            ans.push_back(smallAns);
            return 1;
        }
        vis[src]=1;
        int count=0;
        for(int i=0; i<graph[src].size(); i++)
        {
            if(vis[graph[src][i]]!=1)
            {
                vector<int> temp = smallAns;
                temp.push_back(graph[src][i]);
                count+=dfs(graph,vis,graph[src][i],dest, temp, ans);
            }
        }
        vis[src]=0;
        return count;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> ans;
        vector<int> vis(n,0), smallAns;
        smallAns.push_back(0);
        int a = dfs(graph,vis,0,n-1,smallAns, ans);
        return ans;
    }
};