// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int findSubArraySum(int Arr[], int N, int k)
    {
        int e=0, sum=0, ans=0;
        unordered_map<int,int> map;
        while(e<N)
        {
            sum+=Arr[e];
            if(sum==k)
                ans++;
            // if(map.find(sum-k)!=map.end())
            ans+=map[sum-k];
            map[sum]++;
            e++;
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