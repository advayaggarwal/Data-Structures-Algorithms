//Time complexity - O(n^x), x denotes the number of empty cells

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        int n = board.size();

        solveSudoku(board, 0, 0, n);
    }

    bool solveSudoku(vector<vector<char>>& board, int i, int j, int n)
    {
        if (i == n)
        {
            return true;
        }

        if (j == n)    return solveSudoku(board, i + 1, 0, n);

        //prefilled cell
        if (board[i][j] != '.')    return solveSudoku(board, i, j + 1, n);

        for (int no = 1; no <= 9; no++)
        {
            if (isSafe(board, i, j, no, n))
            {
                board[i][j] = '0' + (no - 0);
                if (solveSudoku(board, i, j + 1, n))   return true;
            }
        }


        board[i][j] = '.';
        return false;
    }

    bool isSafe(vector<vector<char>>& board, int i, int j, int no, int n)
    {
        //check for row and column
        for (int k = 0; k < n; k++)
        {
            if (board[i][k] == ('0' + no) || board[k][j] == ('0' + no))   return false;
        }

        //check for subgrid
        int sqrt_n = sqrt(n);
        int sx = (i / sqrt_n) * sqrt_n; //x coordinate of starting point
        int sy = (j / sqrt_n) * sqrt_n; //y coordinate of starting point
        for (int x = sx; x < sx + sqrt_n; x++)
        {
            for (int y = sy; y < sy + sqrt_n; y++)
            {
                if (board[x][y] == ('0' + no))    return false;
            }
        }

        return true;
    }

};



class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        int n = board.size();
        solve(board, n);
    }

    bool solve(vector<vector<char>>& board, int n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == '.')
                {
                    for (int no = 1; no <= n; no++)
                    {
                        if (isSafe(board, i, j, no, n))
                        {
                            board[i][j] = '0' + no;
                            if (solve(board, n))  return true;
                            else board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool isSafe(vector<vector<char>>& board, int i, int j, int no, int n)
    {
        //check for row and column
        for (int k = 0; k < n; k++)
        {
            if (board[i][k] == ('0' + no) || board[k][j] == ('0' + no))   return false;
        }

        //check for subgrid
        int sqrt_n = sqrt(n);
        int sx = (i / sqrt_n) * sqrt_n; //x coordinate of starting point
        int sy = (j / sqrt_n) * sqrt_n; //y coordinate of starting point
        for (int x = sx; x < sx + sqrt_n; x++)
        {
            for (int y = sy; y < sy + sqrt_n; y++)
            {
                if (board[x][y] == ('0' + no))    return false;
            }
        }

        return true;
    }

};