class Solution {
public:
    int findPar(vector<int> &par, int u)
    {
        return par[u]==u ? u : par[u]=findPar(par,par[u]);
    }
    
    bool equationsPossible(vector<string>& equations) {
        int n=equations.size();
        vector<int> par;
        
        for(int i=0; i<26; i++)
            par.push_back(i);
        
        for(int i=0; i<n; i++)
        {
            string str = equations[i];
            if(str[1]=='=')
            {
                int p1 = findPar(par,str[0]-'a');
                int p2 = findPar(par,str[3]-'a');
                if(p1!=p2)
                    par[p1]=p2;
            }
        }
        for(int i=0; i<n; i++)
        {
            string str = equations[i];
            if(str[1]=='!')
            {
                int p1 = findPar(par,str[0]-'a');
                int p2 = findPar(par,str[3]-'a');
                if(p1==p2)
                    return false;
            }
        }
        
        return true;
    }
};