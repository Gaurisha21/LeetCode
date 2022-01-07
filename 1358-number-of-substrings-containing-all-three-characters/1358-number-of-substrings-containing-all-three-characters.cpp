class Solution {
public:
    int numberOfSubstrings(string str) {
        int s=0, e=0, n=str.length(), count=0, ans=0;
        string t = "abc";
        vector<int> freq (128,0);
        for(int i=0; i<3; i++)
            freq[t[i]]++;
        while(e<n)
        {
            if(freq[str[e++]]--==1) count++;
            while(count==3)
            {
                ans = ans+(n-e)+1;
                if(freq[str[s++]]++==0) count--;
            }
        }
        return ans;
    }
};