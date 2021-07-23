class Solution {
public:
    string reverse(string &sub)
    {
        int i = 0, j = sub.size()-1;
        while(i<=j){ 
            swap(sub[i], sub[j]);
            i++;
            j--;    
        }
        return sub;
    }
    string reverseWords(string s) {
        int i=0, n=s.size();
        
        string ans = "";
        while(i<n)
        {
            while(i<n and s[i]==' ') i++;
            int j=i;
            if(i>n) break;
            while(i<n and s[i]!=' ') i++;
            string sub = s.substr(j,i-j);
            sub = reverse(sub);
            if(ans.size()==0)
                ans+=sub;
            else
                ans = ans + " " + sub;
        }
        return ans;
    }
};