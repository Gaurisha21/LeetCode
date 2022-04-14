class Solution {
public:
    string removeKdigits(string s, int k) {
        stack<int> st;
        st.push(-1);
        int n=s.length(), K=0, i;
        if(n==k) return "0";
        for(i=0; i<n; i++)
        {
            int str = s[i]-'0';
            while(st.top()!=-1 and st.top()>str and k>0)
            {
                k--;
                st.pop();
            }
            st.push(str);
        }
        while(k-->0)
            st.pop();
        string ans="";
        while(!st.empty() and st.top()!=-1)
        {
            ans.push_back(st.top()+'0');
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        while(ans[0]=='0')
            ans.erase(0,1);
        return ans.length()==0 ? "0" : ans;
    }
};