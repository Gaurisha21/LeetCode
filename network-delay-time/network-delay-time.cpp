class Solution {
public:
    int dijkstr(vector<vector<pair<int,int>>> &graph, int V, int src)
    {
        vector<bool>vis(V+1, false);
        vector<int> dis(V+1, 1e8);
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,src});
        while(pq.size()!=0)
        {
            pair<int,int> p = pq.top();
            pq.pop();
            if(vis[p.second]) continue;
            vis[p.second] = true;
            dis[p.second] = p.first;
            for (pair<int,int> e : graph[p.second])
            {
                if (!vis[e.first])
                    pq.push({p.first + e.second,e.first});
            }
        }
        int maxTime = 0;
        for(int i=1; i<=V; i++)
        {
            if(dis[i] == 1e8) return -1;
            maxTime = max(maxTime, dis[i]);
        }
        return maxTime;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n+1,vector<pair<int,int>>());
        for(vector<int>& time : times){
            graph[time[0]].push_back({time[1],time[2]});
        }
        
        return dijkstr(graph,n,k);
    }
};