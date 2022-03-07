class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        vector<int> freq(128,0);
        int s=0, e=0, n=str.length(), count=0, len=INT_MIN;
        if(n<=1) return n;
        while(e<n)
        {
            if(freq[str[e++]]++==1) count++;
            while(count>0)
            {
                if(freq[str[s++]]--==2) count--;
            }
            len=max(len,(e-s));
        }
        return len;
    }
};