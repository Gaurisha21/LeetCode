class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int col=matrix[0].size(), row=matrix.size();
        cout<<row<<" "<<col<<endl;
        //return true;
        int i=0, j=col-1;
        while( i<row and j>=0)
        {
            if(matrix[i][j]==target) return true;
            else if(matrix[i][j]>target) j--;
            else i++;
        }
        return false;
    }
};