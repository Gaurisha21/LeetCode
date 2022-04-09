class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int> st;
        st.push(s[0]);
        int n=s.length();
        for(int i=1; i<n; i++)
        {
            if(st.empty() or st.top()==s[i] or st.top()==')' and s[i]=='(') 
            {
                st.push(s[i]);
                continue;
            }
            else if(st.top()=='(' and s[i]==')')
                st.pop();           
        }
        return st.size();
    }
};