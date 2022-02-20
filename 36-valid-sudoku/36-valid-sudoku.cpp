class Solution {
public:
    bool isSafeToPlace(vector<vector<char>> board, int r, int c, int num)
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

    bool sudoku(vector<int> empty,vector<vector<char>> board)
    {
        for(int i=0; i<empty.size(); i++)
        {
            int cell = empty[i];
            int r = cell/9;
            int c = cell%9;
            int num = board[r][c]-'0';
            board[r][c] = '#';
            if(!isSafeToPlace(board,r,c,num))
                return false;
            board[r][c] = num+'0';
        }
        return true;;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> empty;
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                if(board[i][j]!='.')
                    empty.push_back(i*9+j);
            }
        }
        return sudoku(empty,board);
    }
};