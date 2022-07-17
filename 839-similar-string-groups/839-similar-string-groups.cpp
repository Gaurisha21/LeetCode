class Solution {
public:
    bool isSim(string s1, string s2)
    {
        int n=s1.length(), count=0;
        for(int i=0; i<n; i++)
        {
            if(s1[i]!=s2[i])
            {
                count++;
                if(count>2)
                    return false;
            }
        }
        return true;
    }
    
    int findPar(vector<int> &par, int u)
    {
        return par[u]==u ? u : (par[u]=findPar(par,par[u]));
    }
    
    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size(), no=n;
        vector<int> par(n);
        
        for(int i=0; i<n; i++)
            par[i]=i;
        
        for(int i=0; i<n ; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(isSim(strs[i],strs[j]))
                {
                    int p1 = findPar(par, i);
                    int p2 = findPar(par, j);
                    if(p1!=p2)
                    {
                        no--;
                        par[p1]=p2;
                    }
                }
            }
        }
        return no;
    }
};





