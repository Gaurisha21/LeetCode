class Solution {
public:
    bool isSafeToPlace(vector<vector<char>> &board, int r, int c, int num)
    {
        for(int i=0; i<9; i++)
        {
            if((board[r][i]-'0')==num) return false;
            if((board[i][c]-'0')==num) return false;
        }
        r = (r/3)*3;
        c = (c/3)*3;
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
                if((board[r+i][c+j]-'0') == num) return false;
        }           
        return true;                    
    }

    bool sudoku(vector<int> empty,vector<vector<char>> &board, int idx)
    {
        if(idx==empty.size())
            return true;

        int cell = empty[idx];
        int r = cell/9;
        int c = cell%9;

        for(int i=1; i<=9; i++)
        {
            if(isSafeToPlace(board,r,c,i))
            {
                board[r][c] = (i+'0');
                if(sudoku(empty,board,idx+1))
                    return true;
                board[r][c] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<int> empty;
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                if(board[i][j]=='.')
                    empty.push_back(i*9+j);
            }
        }
        bool flag = sudoku(empty,board,0);
        return;
    }
};