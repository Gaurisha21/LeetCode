class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.length(), maxLen=0;
        stack<int> st;
        st.push(-1);
        for(int i=0; i<n; i++)
        {
            if(s[i]==')' and st.top()!=-1 and s[st.top()]=='(')
            {
                st.pop();
                int len = i-st.top();
                maxLen=max(maxLen,len);
             
            }
            else
                st.push(i);
        }
        return maxLen;
    }
};