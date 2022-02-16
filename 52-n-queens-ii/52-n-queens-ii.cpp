class Solution {
public:
    // bool isSafeToPlace(vector<vector<int>> dir, vector<vector<bool>> board, int r, int c)
    // {
    //     int n=board.size();
    //     for(int d=0; d<dir.size(); d++)
    //     {
    //         for(int rad=1; rad<n; rad++)
    //         {
    //             int R = r + rad*dir[d][0];
    //             int C = c + rad*dir[d][1];
    //             if(R>=0 and C>=0 and R<n and C<n) 
    //             {
    //                 if(board[R][C]) return false;
    //             }
    //             else break;
    //         }
    //     }
    //     return true;
    // }
    vector<bool> row,col,diag,adiag;
    int nQueenComb_sub(int q, int b, int n)
    {
        // int n=q;
        if(q==0)
            return 1;
        int count=0;
        for(int i=b; i<n*n; i++)
        {
            int r=i/n, c=i%n;
            if(!row[r] and !col[c] and !diag[r+c] and !adiag[r-c+n-1])
            {
               row[r] = col[c] = diag[r+c] = adiag[r-c+n-1] = true;
                count+=nQueenComb_sub(q-1,i+1,n);
                row[r] = col[c] = diag[r+c] = adiag[r-c+n-1] = false;
            } 
        }
        return count;
    }
    int totalNQueens(int n) {
        // vector<vector<int>> dir {{0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1}};
        // vector<vector<bool>> board(n,vector<bool>(n,false));
        row.resize(n,false);
        col.resize(n,false);
        diag.resize(2*n-1,false);
        adiag.resize(2*n-1,false);
        return nQueenComb_sub(n,0,n);
    }
};