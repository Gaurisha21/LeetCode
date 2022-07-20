class Solution {
public:
    int findPar(vector<int>&par, int u)
    {
        return par[u]==u ? u : par[u]=findPar(par,par[u]);
    }
    int regionsBySlashes(vector<string>& grid) {
        int n=grid.size(), N=n+1, ans=1;
        vector<int> par(N*N);
        
        for(int i=0; i<N*N; i++)
        {
            if(i/N==0 || i%N==0 || i/N==N-1 || i%N==N-1)
                par[i]=0;
            else 
                par[i]=i;
        }
        
        for(int i=0; i<n; i++)
        {
            string s = grid[i];
            for(int j=0; j<s.length(); j++)
            {
                if(s[j]=='/')
                {
                    int p1 = findPar(par, i*N+(j+1));
                    int p2 = findPar(par, (i+1)*N+j);
                    if(p1!=p2)
                    {
                        par[p1]=min(p1,p2);
                        par[p2]=min(p1,p2);
                    }
                    else 
                        ans++;
                }
                else if(s[j]=='\\')
                {
                    int p1 = findPar(par, i*N+j);
                    int p2 = findPar(par, (i+1)*N+(j+1));
                    if(p1!=p2)
                    {
                        par[p1]=min(p1,p2);
                        par[p2]=min(p1,p2);
                    }
                    else 
                        ans++;
                }
            }
        }
        return ans;
    }
};