class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n= temp.size();
        vector<int> ans(n,0);
        stack<int> st;
        st.push(-1);
        for(int i=n-1; i>=0; i--)
        {
            while(st.top()!=-1 and temp[i]>=temp[st.top()])
                st.pop();
            ans[i] = (st.top()-i)>0 ? st.top()-i : 0 ;
            st.push(i);
        }
        return ans;
    }
};