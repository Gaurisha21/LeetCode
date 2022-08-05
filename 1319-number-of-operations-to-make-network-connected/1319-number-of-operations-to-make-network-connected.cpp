class Solution {
public:
    void dfs(vector<vector<int>> &graph, int src, vector<int> &vis)
    {
        vis[src]=1;
        for(int i=0; i<graph[src].size(); i++)
        {
            if(vis[graph[src][i]]==0)
                dfs(graph,graph[src][i], vis);
        }
    }
    
    int findPar(vector<int> &par, int u)
    {
        return par[u]==u ? u : par[u]=findPar(par,par[u]);
    }
    
    int unionFind(vector<vector<int>> &connections, int n)
    {
        int t=connections.size(),edge=0;
        vector<int> par(n);
        vector<int> size(n,1);
        for(int i=0; i<n; i++)
            par[i]=i;
        
        for(int i=0; i<t; i++)
        {
            int u=connections[i][0], v=connections[i][1];
            int p1=findPar(par,u);
            int p2=findPar(par,v);
            if(p1==p2)
                edge++;
            else
            {
                if(size[p1]>size[p2])
                {
                    par[p2]=p1;
                    size[p1]+=size[p2];
                }
                else
                {
                    par[p1]=p2;
                    size[p2]+=size[p1];
                }
            }
        }
        return edge;
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        int t=connections.size();
        if(t<n-1)
            return -1;
        vector<vector<int>> graph(n);
        vector<int> vis(n,0);
        for(int i=0; i<t; i++)
        {
            graph[connections[i][0]].push_back(connections[i][1]);
            graph[connections[i][1]].push_back(connections[i][0]);
        }
        
        int comp=-1;
        for(int i=0; i<n; i++)
        {
            if(vis[i]==0)
            {
                comp++;
                dfs(graph,i,vis);
            }
        }
        cout<<comp<<endl;
        
        int edge = unionFind(connections, n);
        return edge<comp ? -1 : comp;
    }
};