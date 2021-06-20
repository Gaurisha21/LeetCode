class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int r, int c, int num)
    {
        for(int i=0; i<9; i++) 
        {
            if(board[r][i]-'0'==num) return false;
        }
        for(int i=0; i<9; i++) 
        {
            if(board[i][c]-'0'==num) return false;
        }
        int R=(r/3)*3, C=(c/3)*3;
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                if(board[R+i][C+j]-'0'==num) return false;
            }
        }
        return true;
    }
    bool solveSudoku(vector<vector<char>>& board, vector<int> emptyInd, int idx)
    {
        if(idx==emptyInd.size()) return true;
        int cell=emptyInd[idx];
        int r=cell/9, c=cell%9;
        for(int num=1; num<=9; num++)
        {
            if(isSafe(board, r, c, num))
            {
                board[r][c] = char(num+'0');
                if(solveSudoku(board, emptyInd, idx+1))
                    return true;
                board[r][c] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<int> emptyInd;
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                if(board[i][j]=='.')
                    emptyInd.push_back(i*9+j);
            }
        }
        solveSudoku(board, emptyInd, 0);
    }
};