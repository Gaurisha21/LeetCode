class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        int n=arr.size();
        vector<int> narr(n,-1);
        stack<int> st;
        st.push(-1);
        for(int i=0; i<2*n; i++)
        {
            while(st.top()!=-1 and arr[i%n]>arr[st.top()])
            {
                narr[st.top()]=arr[i%n];
                st.pop();
            }
            if(i<n)st.push(i);
        }
        return narr;
    }
};