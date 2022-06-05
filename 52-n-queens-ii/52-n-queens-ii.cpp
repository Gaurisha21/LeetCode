class Solution {
public:
    vector<bool> row, col, diag, adiag;
    int queen(int q, int n, int b)
    {
        if(q==0)
            return 1;
        int count=0;
        for(int i=b; i<n*n; i++)
        {
            int r=i/n, c=i%n;
            if(!row[r] and !col[c] and !diag[r+c] and !adiag[r-c+n-1])
            {
                row[r] = col[c] = diag[r+c] = adiag[r-c+n-1] = true;
                count+=queen(q-1, n, i+1);
                row[r] = col[c] = diag[r+c] = adiag[r-c+n-1] = false;
            }
        }
        return count;
    }
    int totalNQueens(int n) {
        row.resize(n,false);
        col.resize(n,false);
        diag.resize(2*n-1,false);
        adiag.resize(2*n-1,false);
        return queen(n,n,0);
    }
};