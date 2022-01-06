class Solution {
public:
    int countGoodSubstrings(string str) {
        int s=0, e=0, n=str.length(), count=0, ans= 0, dis=0;
        vector<int> freq (128,0);
        while(e<n)
        {
            if(freq[str[e++]]++ == 0) dis++;
            count++;
            while(count==3)
            {
                if(dis==3){
                    ans++;
                    // cout<<s<<" "<<e<<" "<<ans<<endl;
                }
                if(freq[str[s++]]-- >=1)
                {
                    if(freq[str[s-1]]==0)
                        dis--;
                    count--;
                }
            }
        }
        return ans;
    }
};