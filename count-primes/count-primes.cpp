class Solution {
public:
    int countPrimes(int n) {
        vector<bool> t(n, true);
        for(int i=2;i*i<n;i++)
        {
            if(!t[i])
                continue;
            for(int j = i*i; j<n; j+=i)
            {
                t[j]=false;
            }
        }
        int ans=0;
        for(int i=2; i<n;i++)
        {
            if(t[i])
                ans++;
        }
        return ans;
    }
};