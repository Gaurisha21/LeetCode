class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(vector<int> &e : prerequisites)
            graph[e[0]].push_back(e[1]);
        
        vector<int> inDegree(numCourses,0);
        for(vector<int> & edgeList : graph)
        {
            for(int v : edgeList)
                inDegree[v]++;
        }
        
        queue<int> que, ans;
        for(int i=0; i<numCourses; i++)
        {
            if(inDegree[i]==0) que.push(i);
        }
        int level = 0;
        while(que.size()!=0)
        {
            int size = que.size();
            while(size-->0)
            {
                int vrt = que.front();
                que.pop();
                ans.push(vrt);
                for(int v : graph[vrt])
                {
                    if(--inDegree[v] == 0) que.push(v);
                }
            }
        }
        if(ans.size()!=numCourses) return false;
        return true;
    }
};



















