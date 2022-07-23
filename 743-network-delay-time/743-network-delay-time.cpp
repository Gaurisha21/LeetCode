class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        vector<vector<pair<int,int>>> graph(n+1);
        vector<int> vis(n+1,0);
        int ans = INT_MIN;
        
        for(vector<int>& time : times){
            graph[time[0]].push_back({time[1],time[2]});
        }
        
        pq.push({0,k});
        
        while(!pq.empty())
        {
            int size = pq.size();
            while(size--)
            {
                vector<int> node = pq.top();
                pq.pop();
                if(vis[node[1]]==1)
                    continue;
                ans = max(ans,node[0]);
                vis[node[1]]=1;
                for (pair<int,int> e : graph[node[1]])
                {
                    if (vis[e.first]!=1)
                        pq.push({node[0]+e.second,e.first});
                }
            }
        }
        
        
        for(int i=1; i<n+1; i++)
        {
            if(vis[i]==0)
                return -1;
        }
        
        return ans;
    }
};