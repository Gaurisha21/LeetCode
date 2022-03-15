// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int kadane(vector<int> arr)
    {
        int cs=0, gs=INT_MIN, n=arr.size();
        for(int i=0; i<n; i++)
        {
            cs=max(arr[i],cs+arr[i]);
            gs=max(gs,cs);
        }
        return gs;
    }
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        int ans=INT_MIN;
        for(int firstRow=0; firstRow<R; firstRow++)
        {
            vector<int> a(C,0);
            for(int row=firstRow; row<R; row++)
            {
                for(int col=0; col<C; col++)
                    a[col]+=M[row][col];
                ans=max(ans,kadane(a));
            }
        }
        return ans;
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}  // } Driver Code Ends