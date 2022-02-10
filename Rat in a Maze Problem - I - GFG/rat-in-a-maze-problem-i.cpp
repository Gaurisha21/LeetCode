// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++



class Solution{
    public:
    int maze(int sr, int sc, vector<vector<int>> dir, vector<string> dirS, string s, vector<vector<int>> &m, vector<string> &ans)
    {
        int n=m.size();
        if(sr==n-1 and sc==n-1)
        {
            ans.push_back(s);
            return 1;
        }
        int count=0;
        m[sr][sc]=0;
        for(int d=0; d<dir.size(); d++)
        {
            int r=sr+dir[d][0];
            int c=sc+dir[d][1];
            if(r>=0 and c>=0 and r<n and c<n and m[r][c]==1)
            {
                count+=maze(r,c,dir,dirS,s+dirS[d],m,ans);
            }
        }
        m[sr][sc]=1;
        return count;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<vector<int>> dir{{-1,0},{1,0},{0,-1},{0,1}};
        vector<string> dirS{"U","D","L","R"};
        vector<string> ans;
        string s="";
        if(m[0][0]==0 || m[n-1][n-1]==0) return ans;
        int count=maze(0,0,dir,dirS,"",m,ans);
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends