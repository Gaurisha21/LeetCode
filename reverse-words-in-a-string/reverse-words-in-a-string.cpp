class Solution {
public:
    string reverseWords(string s) {
        int i=s.size()-1;
        string ans = "";
        while(i>=0)
        {
            while(i>=0 and s[i]==' ') i--;
            int j=i;
            if(i<0) break;
            while(i>=0 and s[i]!=' ') i--;
            if(ans.size()==0)
                ans+=s.substr(i+1,j-i);
            else
                ans = ans + " " + s.substr(i+1,j-i);
        }
        return ans;
    }
};