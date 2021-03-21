class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans=0;
        int i=s.size()-1;
        
        if(s[i]==' ')
        {
            while(i>=0 && s[i]==' ')
            {
                i--;
            }
        }
        while(i>=0 && s[i]!=' ')
        {
            ans++;
            i--;
        }
        return ans;
    }
};