// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int findSubArraySum(int arr[], int N, int k)
    {
        unordered_map<int,int> mp;
        int ans=0, cumsum=0;
        for(int i=0; i<N; i++)
        {
            cumsum+=arr[i];
            if(cumsum==k) ans++;
            if(mp.find(cumsum-k)!=mp.end()) 
                ans+=mp[cumsum-k];
            mp[cumsum]++;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.findSubArraySum(Arr, N, k)<<endl;
    }
    return 0;
}  // } Driver Code Ends