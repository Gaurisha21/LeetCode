class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<vector<int>> graph(n);
        vector<int> inDeg(n,0);
        int i=0;
        for(int i=0; i<roads.size(); i++)
        {
            graph[roads[i][0]].push_back(roads[i][1]);
            graph[roads[i][1]].push_back(roads[i][0]);
        }
        
        for(vector<int> arr: graph)
        {
            for(int ele : arr)
                inDeg[ele]++;
        }
        
        sort(inDeg.begin(), inDeg.end());
        
        long long total = 0;
        for (int i = 0; i < n; ++i) 
        {
            // cout<<i + 1<<" "<< inDeg[i]<<endl;
            total += (long long)(i + 1) * inDeg[i];
        }
        return total;
    }
};