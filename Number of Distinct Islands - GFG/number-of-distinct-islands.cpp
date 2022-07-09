// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  void gcc(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dir, vector<string> dirStr, string &psf, set<string> &st)
    {
        int n=grid.size(), m=grid[0].size();
        grid[i][j]=0;
        for(int d=0; d<dir.size(); d++)
        {
            int r=i+dir[d][0];
            int c=j+dir[d][1];
            if(r>=0 and r<n and c>=0 and c<m and grid[r][c]==1)
            {
                psf+=dirStr[d];
                gcc(grid,r,c,dir,dirStr,psf,st);
            }
        }
        psf+="b";
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        vector<string>dirStr{"r","l","d","u"};
        set<string> st;
        int n=grid.size(), m=grid[0].size();
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==1)
                {
                    string psf="";
                    gcc(grid,i,j,dir,dirStr,psf,st);
                    st.insert(psf);
                }
            }
        }
        // for (auto itr : st)
        //   {
        //     cout << itr << " ";
        //   } 
        return st.size();
    }
};


// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}  // } Driver Code Ends