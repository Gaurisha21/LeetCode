class Solution {
public:
    vector<int> par;
    int findPar(int u)
    {
        return par[u]==u ? u : (par[u] = findPar(par[u]));
    }
    int findCircleNum(vector<vector<int>>& graph) {
        int n = graph.size(), comp = n;
        for(int i = 0; i<n; i++)
            par.push_back(i);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(graph[i][j] == 1)
                {
                    int p1 = findPar(i);
                    int p2 = findPar(j);
                    if(p1!=p2)
                    {
                        par[p1] = p2;
                        comp--;
                    }
                }
            }
        }
        return comp;
    }
};