class Solution {
public:
    int brokenCalc(int st, int k) {
        long long int s=st, ans=0, t=k;
        while(t!=s)
        {
            if(t==s) return ans;
            if(t>s)
            {
                if(t%2==0) t/=2;
                else t+=1;
            }
            else t+=1;
            ans++;
        }
        return ans;
    }
};