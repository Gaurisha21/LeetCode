class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& edges, int src, int dst, int k) {
        bool cycle = false;
        k++;
        vector<int> prev(n,(int) 1e9), curr(n,(int) 1e9);
        
        prev[src]=0;
        
        for(int i=1; i<=n-1; i++)
        {
            curr = prev;
            bool update= false;
            for(vector<int> e : edges)
            {
                int u=e[0], v=e[1], w=e[2];
                if(curr[v]>prev[u]+w)
                {
                    curr[v]=prev[u]+w;
                    update = true;
                }
            }
            
            if(i==n and update)
            {
                cycle = true;
                break;
            }
            
            prev = curr;
            
            if(!update)
                break;
            
            k--;
            if(k==0)
                break;
        }
        
        return curr[dst] == (int) 1e9 ? -1 : curr[dst];
    }
};