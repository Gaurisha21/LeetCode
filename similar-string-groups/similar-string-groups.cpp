class Solution {
public:
    bool isSimilar(string s1, string s2)
    {
        int count=0;
        for(int i=0; i<s1.length(); i++)
        {
            if(s1[i]!=s2[i] && ++count>2) return false;
        }
        return true;
    }
    
    vector<int> par;
    
    int findPar(int u)
    {
        return par[u] ==u ? u : (par[u] = findPar(par[u]));
    }
    
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        int set = n;
        for(int i=0; i<n; i++)
            par.push_back(i);
        
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(isSimilar(strs[i], strs[j]))
                {
                    int p1 = findPar(i);
                    int p2 = findPar(j);
                    if(p1!=p2)
                    {
                        par[p1] = p2;
                        set--;
                    }
                }
            }
        }
        return set;
    }
};