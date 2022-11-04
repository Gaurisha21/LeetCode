//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int max_sum(int A[],int N);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
        {
            cin>>A[i];
        }

        cout<<max_sum(A,N)<<endl;
        /*keeping track of the total sum of the array*/

    }
}

// } Driver Code Ends


/*You are required to complete this method*/
int max_sum(int arr[],int n)
{
    int cs=0, ps=0, ans=INT_MIN;
    for(int i=0; i<n; i++)
    {
        cs+=arr[i];
        ps+=(i*arr[i]);
    }
        
    for(int i=1; i<=n; i++)
    {
        ans=max(ans,ps);
        ps = ps-cs+(n*arr[i-1]);
    }
    
    return ans;
}