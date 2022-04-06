// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        vector<long long> narr(n,-1);
        stack<int> st;
        st.push(-1);
        for(long long i=0; i<n; i++)
        {
            while(st.top()!=-1 and arr[i]>arr[st.top()])
            {
                narr[st.top()]=arr[i];
                st.pop();
            }
            st.push(i);
        }
        return narr;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}  // } Driver Code Ends