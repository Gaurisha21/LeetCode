class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n=s.length();
        stack<int> st;
        for(int i=0; i<n; i++)
        {
            if(s[i]!='(' and s[i]!=')')
                continue;
            else if(!st.empty() and (s[st.top()]=='(' and s[i]==')'))
                st.pop();
            else
                st.push(i);
        }
        for(int i=n-1; i>=0; i--)
        {
            if(!st.empty() and st.top()==i)
            {
                s.erase(i,1);
                st.pop();
            }
        }
        return s;
    }
};