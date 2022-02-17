class Solution {
public:
    vector<bool> row, col, diag, adiag;
   int nQueenComb3(int n,int q, int r,vector<vector<int>>coord, vector<vector<string>> &ans,vector<string> ww)
    {
        // int n=board.size();
        if(q==0)
        {
            for(vector<int> k:coord)
            {
                int x=k[0], y=k[1];
                ww[x][y]='Q';
            }
            ans.push_back(ww);
            return 1;
        }
        int count=0;
        for(int c=0; c<n; c++)
        {
            // int r=, c=i%n;
            if(!row[r] and !col[c] and !diag[r+c] and !adiag[r-c+n-1])
            {
                vector<vector<int>> e = coord;
                row[r] = col[c] = diag[r+c] = adiag[r-c+n-1] = true;
                coord.push_back({r,c});
                count+=nQueenComb3(n,q-1,r+1,coord,ans,ww);
                coord = e;
                row[r] = col[c] = diag[r+c] = adiag[r-c+n-1] = false;
            } 
        }
        return count;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> arr;
        vector<string> ans(n,string(n,'.'));
         // for(string s:ans)
         //     cout<<s<<" ";
        vector<vector<int>> coord;
        row.resize(n,false);
        col.resize(n,false);
        diag.resize((2*n-1),false);
        adiag.resize((2*n-1),false);
        int d = nQueenComb3(n,n,0, coord,arr,ans);
        // for(vector<string> t: arr)
        // {
        //     for(string s:t)
        //         cout<<s<<" ";
        //     cout<<endl;
        // }
        return arr;
    }
};