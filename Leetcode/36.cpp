//Time complexity - O(n^3)
//Space complexity - O(1)
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        int n = 9;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == '.')  continue;

                if (!isValid(i, j, board))   return false;
            }
        }

        return true;
    }

    bool isValid(int i, int j, vector<vector<char>>& board)
    {
        for (int row = 0; row < i; row++)
        {
            if (board[row][j] == board[i][j])    return false;
        }

        for (int col = 0; col < j; col++)
        {
            if (board[i][col] == board[i][j])    return false;
        }

        int rs = 3 * (i / 3), cs = 3 * (j / 3); //starting row and col of block

        for (int r = rs; r < rs + 3; r++)
        {
            for (int c = cs; c < cs + 3; c++)
            {
                if (r != i && c != j && board[r][c] == board[i][j])  return false;
            }
        }

        return true;
    }
};


//Time complexity - O(n^2)
//Space complexity - O(n^2)
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        int n = 9;
        int rows[9][9] = {0}; //rows[5][0] means whether number 1('0'+1) in row 5 has appeared.
        int cols[9][9] = {0}; //cols[3][8] means whether number 9('8'+1) in col 3 has appeared.
        int blocks[3][3][9] = {0}; //blocks[0][2][5] means whether number '6' in block 0,2 (row 0~2,col 6~8) has appeared.
        //i.e. 9 quadrants are there viz (0,0) ... (2,2)
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == '.')  continue;

                int number = board[i][j] - '1';

                if (rows[i][number]++)    return false;
                if (cols[j][number]++)    return false;

                if (blocks[i / 3][j / 3][number]++)    return false;
            }
        }

        return true;
    }
};