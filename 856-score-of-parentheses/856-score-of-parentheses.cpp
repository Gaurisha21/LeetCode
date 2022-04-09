class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        int n=s.length();
        st.push(0);
        for(int i=0; i<n; i++)
        {
            if(s[i]=='(')
                st.push(0);
            else
            {
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                int val = b+max(2*a,1);
                st.push(val);
            }
        }
        return st.top();
    }
};