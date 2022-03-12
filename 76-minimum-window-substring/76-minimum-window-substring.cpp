class Solution {
public:
    string minWindow(string str, string t) {
        vector<int> freq(128,0);
        int n=str.length(), m=t.length(), s=0, e=0, count=0, len=INT_MAX, ge=0,gs=0;
        if(n<m) return "";
        for(int i=0; i<m; i++)
            freq[t[i]]++;
        while(e<n)
        {
            if(freq[str[e++]]-->=1) count++;
            while(count==m)
            {
                if(e-s<len)
                {
                    ge=e;
                    gs=s;
                    len=(e-s);
                }
                if(freq[str[s++]]++==0) count--;
            }
        }
        return len==INT_MAX ? "" : str.substr(gs,len);
    }
};