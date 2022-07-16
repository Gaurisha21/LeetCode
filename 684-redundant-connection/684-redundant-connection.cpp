class Solution {
public:
    int findParent(vector<int> &par, int u)
    {
        return par[u]==u ? u : (par[u]=findParent(par, par[u]));
    }
    
    void merge(vector<int> & par, vector<int> &size, int p1, int p2)
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
        
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        vector<int> par, size(n,1);
        
        for(int i=0; i<n; i++)
            par.push_back(i);
        
        for(vector<int> e : edges)
        {
            int u=e[0], v=e[1];
            int p1=findParent(par,u);
            int p2=findParent(par,v);
            if(p1==p2)
                return e;
            else
                merge(par,size,p1,p2);
        }
        return {};
    }
};












