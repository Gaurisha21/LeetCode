class NumMatrix {
public:
    vector<vector<int>> arr;
    void cumSum(vector<vector<int>> &arr)
    {
        int R=arr.size(), C=arr[0].size();
        for(int r=1; r<R; r++)
        {
            for(int c=0; c<C; c++)
                arr[r][c] += arr[r-1][c];
        }
        for(int c=1; c<C; c++)
        {
            for(int r=0; r<R; r++)
                arr[r][c] += arr[r][c-1];
        }
        // cout<<arr[R-1][C-1]<<endl;
    }
    NumMatrix(vector<vector<int>>& mat) {
        arr = mat;
        cumSum(arr);
    }
    
    int sumRegion(int r1, int c1, int r2, int c2) {
        // cout<<arr[r2][c2]<<" - "<<arr[r1-1][c2]<<" - "<<
        return arr[r2][c2]-(r1-1>=0 ? arr[r1-1][c2] : 0)-(c1-1>=0 ? arr[r2][c1-1] : 0) + (r1-1>=0 and c1-1>=0 ? arr[r1-1][c1-1] : 0);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */