// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int kadane(vector<int> nums)
  {
      int n=nums.size(), gsum = INT_MIN, csum = 0;
      for(int i=0; i<n; i++)
      {
          csum=max(nums[i],nums[i]+csum);
          gsum=max(csum,gsum);
      }
      return gsum;
  }
    int maximumSumRectangle(int R, int C, vector<vector<int>> nums) {
        int n=R, m=C, maxSum=INT_MIN;
        
        for(int firstRow=0; firstRow<n; firstRow++)
        {
            vector<int>ans(m,0);
            //fill(ans.begin(),ans.end(),0);
            for(int row=firstRow; row<n; row++)
            {
                for(int col=0; col<m; col++)
                    ans[col]+=nums[row][col];
                int sum=kadane(ans);
                maxSum=max(maxSum,sum);
            }
        }
        return maxSum;
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