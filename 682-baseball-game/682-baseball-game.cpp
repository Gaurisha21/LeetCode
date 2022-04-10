class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        int n=ops.size(), sum=0;
        for(auto it: ops)
        {
            if(it == "C")
                st.pop();
            else if(it == "D")
            {
                int s = st.top();
                st.push(s*2);
            }
            else if(it == "+")
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                int Sum = a+b;
                st.push(a);
                st.push(Sum);
            }
            else
            {
                string a = it;
                int p = stoi(a);
                st.push(p);
            }
        }
        while(!st.empty())
        {
            sum+=st.top();
            st.pop();
        }
        return sum;
    }
};