class Solution {
public:
    vector<int> row;
    vector<int> col;
    vector<vector<int>>mat;
    
    bool isValidSudoku(vector<vector<char>>& board) {
        row.resize(9,0);
        col.resize(9,0);
        mat.resize(3, vector<int>(3,0));            
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]!='.'){
                    int mask = 1<<(board[i][j]-'0');
                    if ((row[i] & mask) == 0 && (col[j] & mask) == 0 && (mat[i / 3][j / 3] & mask) == 0){
                        row[i]^=mask;
                        col[j]^=mask;
                        mat[i/3][j/3]^=mask;
                    }
                    else return false;
                }
            }
        }
        return true;
    }
};