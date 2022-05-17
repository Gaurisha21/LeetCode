class Solution {
public:
    string reverse(string ans)
    {
        int s=0, e=ans.length()-1;
        while(s<=e)
            swap(ans[s++],ans[e--]);
        return ans;
    }
    string removeDuplicates(string s) {
        stack<char> st;
        string ans="";
        st.push(s[0]);
        for(int i=1; i<s.length(); i++)
        {
            if(!st.empty() and st.top()==s[i])
                st.pop();
            else
                st.push(s[i]);
        }
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        ans = reverse(ans);
        return ans;
    }
};