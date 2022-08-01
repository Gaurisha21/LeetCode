class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> inDeg(n), ans;
        vector<vector<int>> graph(n);
        for(vector<int> e:edges)
            graph[e[0]].push_back(e[1]);
        for(vector<int> e:graph)
        {
            for(int ele:e)
                inDeg[ele]++;
        }
        for(int i=0; i<inDeg.size(); i++)
            if(inDeg[i]==0)
                ans.push_back(i);
        return ans;
    }
};