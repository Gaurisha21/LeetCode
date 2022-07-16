class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& edge) {
        vector<int> indeg(numCourses,0), ans, ansB;
        vector<vector<int>> graph(numCourses);
        queue<int> q;
        
        for(int i=0; i<edge.size(); i++)
            graph[edge[i][0]].push_back(edge[i][1]);
        
        for(int i=0; i<graph.size(); i++)
        {
            for(int j=0; j<graph[i].size(); j++)
                indeg[graph[i][j]]++;
        }
        
        for(int i=0; i<indeg.size(); i++)
            if(indeg[i]==0)
                q.push(i);
        
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                int vrt = q.front();
                q.pop();
                for(int i=0; i<graph[vrt].size(); i++)
                {
                    if(--indeg[graph[vrt][i]]==0)
                        q.push(graph[vrt][i]);
                }
                ans.push_back(vrt);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans.size()==numCourses ? ans : ansB;
    }
};