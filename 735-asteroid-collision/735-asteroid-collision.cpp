class Solution {
public:
    vector<int> reverse(vector<int> &ans)
    {
        int s=0, e=ans.size()-1;
        while(s<=e)
            swap(ans[s++],ans[e--]);
        return ans;
    }
    vector<int> asteroidCollision(vector<int>& arr) {
        stack<int> st;
        st.push(arr[0]);
        vector<int> ans;
        int n=arr.size();
        for(int i=1; i<n; i++)
        {
            if(st.empty()) st.push(arr[i]);
            else if(st.top()<0 and arr[i]>0)
            {
                cout<<"Pushing 1: "<<arr[i]<<endl;
                st.push(arr[i]);
            }
            else if(st.top()>0 and arr[i]<0)
            {
                if(st.top()< arr[i]*(-1))
                {
                    while(!st.empty() and st.top()>0 and st.top()< arr[i]*(-1))
                    {
                        cout<<"Poping: "<<st.top()<<endl;
                        st.pop();
                    }
                    if(st.empty() or arr[i]*(-1) > st.top())
                    {
                        cout<<"Pushing 2: "<<arr[i]<<endl;
                        st.push(arr[i]);
                    }
                    else if(st.empty() or arr[i]*(-1) == st.top())
                        st.pop();
                }
                else if(st.top() == arr[i]*(-1)) 
                    st.pop();
                else
                    continue;            
            }
            else 
            {
                cout<<"Pushing 3: "<<arr[i]<<endl;
                st.push(arr[i]);
            }
        }
        if(st.empty()) return {};
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return reverse(ans);
    }
};


