// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
  public:
    //Function to count subarrays with 1s and 0s.
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        for(int i=0; i<n; i++)
            if(arr[i]==0) arr[i]=-1;
        unordered_map<int,int> map;
        map[0]=1;
        int sum=0, ans=0;
        for(int i=0; i<n; i++)
        {
            int ele=arr[i];
            sum+=ele;
            ans+=map[sum];
            map[sum]++;
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