class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int> st;
        st.push(-1);
        int n=temp.size();
        vector<int> ans(n);
        for(int i=n-1; i>=0; i--)
        {
            while(st.top()!=-1 and temp[i]>=temp[st.top()])
                st.pop();
            ans[i] = st.top()==-1 ? 0 : (st.top()-i);
            st.push(i);
        }
        return ans;
    }
};