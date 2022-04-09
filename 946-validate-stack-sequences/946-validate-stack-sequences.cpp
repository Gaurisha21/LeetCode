class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int j=0, n=popped.size(), m=pushed.size();
        for(int i=0; i<m; i++)
        {
            st.push(pushed[i]);
            while(!st.empty() and j<n and st.top()==popped[j])
            {
                st.pop();
                j++;
            }
        }
        if(st.empty()) return true;
        return false;
    }
};