// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    //Function to count subarrays with 1s and 0s.
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        unordered_map<int,int> rem;
        rem[0]=1;
        long long int e=0, ans=0, sum=0;
        for(long long int i=0; i<n; i++)
        {
            if(arr[i]==0) arr[i]=-1;
        }
        // for(long long int i=0; i<n; i++) cout<<arr[i]<<" ";
        // cout<<endl;
        while(e<n)
        {
            int val = arr[e++];
            sum+=val;
            // cout<<"sum = "<<sum<<" ";
            auto it1 = rem.find(sum);
            if (it1 != rem.end())
            {
                ans=ans+rem[sum];
            }
            else
                ans+=0;
            rem[sum]++;
            // cout<<"ans = "<<ans<<" ";
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
	int n,i;
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution obj;
	cout<< obj.countSubarrWithEqualZeroAndOne(arr, n)<<"\n";
	}
	return 0;
}
  // } Driver Code Ends