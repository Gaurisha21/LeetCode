class Solution {
public:
    bool isValid(string s) {
        int n=s.length();
        if(n%2==1) return false;
        stack<char> st;
        if(s[0]==')' || s[0]==']' || s[0]=='}') return false;
        for(int i=0; i<n; i++)
        {
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')
                st.push(s[i]);
            else 
            {
                if(st.empty()) return false;
                else if(s[i]==')')
                {
                    if(st.top()!='(') 
                    {
                        // cout<<i<<" "<<s[i]<<" "<<st.top()<<endl;
                        return false;
                    }
                    else if(st.top()=='(') 
                    {
                        // cout<<i<<" "<<s[i]<<" "<<st.top()<<endl;
                        st.pop();
                    }
                }
                else if(s[i]==']')
                {
                    if(st.top()!='[') 
                    {
                        // cout<<i<<" "<<s[i]<<" "<<st.top()<<endl;
                        return false;
                    }
                    else if(st.top()=='[') 
                    {
                        // cout<<i<<" "<<s[i]<<" "<<st.top()<<endl;
                        st.pop();
                    }
                }
                else if(s[i]=='}')
                {
                    if(st.top()!='{') 
                    {
                        // cout<<i<<" "<<s[i]<<" "<<st.top()<<endl;
                        return false;
                    }
                    else if(st.top()=='{') 
                    {
                        // cout<<i<<" "<<s[i]<<" "<<st.top()<<endl;
                        st.pop();
                    }
                }
            }
        }
        return st.empty() ? true : false;
    }
};