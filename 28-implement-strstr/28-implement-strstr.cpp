class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=needle.size(), h=haystack.size();
        if(n==0) 
            return 0;
        for(int i=0; i<h; i++)
        {
            string w=haystack.substr(i,n);
            if(w==needle)
                return i;
        }
        return -1;
    }
};