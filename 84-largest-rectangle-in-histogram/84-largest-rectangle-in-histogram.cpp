class Solution {
public:
    vector<int> NSR(vector<int> arr)
    {
        stack<int> st;
        st.push(-1);
        int n=arr.size();
        vector<int> narr(n,n);
        for(int i=n-1; i>=0; i--)
        {
            while(st.top()!=-1 && arr[st.top()]>=arr[i])
                st.pop();
            narr[i] = st.top()==-1 ? n : st.top();
            st.push(i);
        }
        return narr;
    }
     vector<int> NSL(vector<int> arr)
    {
        stack<int> st;
        st.push(-1);
        int n=arr.size();
        vector<int> narr(n,-1);
        for(int i=0; i<n; i++)
        {
            while(st.top()!=-1 && arr[st.top()]>=arr[i])
                st.pop();
            narr[i] = st.top()==-1 ? -1 : st.top();
            st.push(i);
        }
        return narr;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nsr, nsl;
        int n=heights.size(), maxArea=INT_MIN;
        nsr = NSR(heights);
        nsl = NSL(heights);
        // for(int ele:nsr)
        //     cout<<ele<<" ";
        // cout<<endl;
        // for(int ele:nsl)
        //     cout<<ele<<" ";
        // cout<<endl;
        for(int i=0; i<n; i++)
        {
            int area = heights[i]*(abs(nsr[i]-nsl[i])-1);
            maxArea=max(area,maxArea);
        }
        return maxArea;
    }
};