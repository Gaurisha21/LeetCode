class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length(), si=0, ei=0, count=0, len=0;
        vector<int> freq(128, 0);
        while(ei<n)
        {
            if(freq[s[ei++]]++>0) count++;
            while(count>0)
                if(freq[s[si++]]-- >1) count--;
            len = max(len, ei-si);
        }
        return len;
    }
};