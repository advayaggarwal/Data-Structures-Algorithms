class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<int>dir = { -1, 0, 1};
        int m = board.size();
        int n = board[0].size();

        for (int row = 0; row < m; row++)
        {
            for (int col = 0; col < n; col++)
            {
                int neighbors = 0;
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        if (!(dir[i] == 0 && dir[j] == 0))
                        {
                            int r = row + dir[i];
                            int c = col + dir[j];

                            if ((r >= 0 && r < m) && (c >= 0 && c < n) && (board[r][c] == 1 || board[r][c] == -1))
                            {
                                neighbors += 1;
                            }
                        }
                    }
                }


                if (board[row][col] == 1)
                {
                    if (neighbors < 2 || neighbors > 3)   board[row][col] = -1;

                }
                else
                {
                    if (neighbors == 3)  board[row][col] = 2;
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] > 0) board[i][j] = 1;
                else board[i][j] = 0;
            }
        }
    }
};

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board)
    {
        int m = board.size(), n = board[0].size();
        int dx[8] = {0, 0, 1, -1, -1, -1, 1, 1};
        int dy[8] = { -1, 1, 0, 0, -1, 1, -1, 1};

        for (int r = 0; r < m; r++)
        {
            for (int c = 0; c < n; c++)
            {
                int neighbors = 0;
                for (int k = 0; k < 8; k++)
                {
                    int row = r + dx[k];
                    int col = c + dy[k];

                    if (row >= 0 && row < m && col >= 0 && col < n && (board[row][col] == 1 or board[row][col] == -1)) neighbors++;
                }

                if (board[r][c] == 1)
                {
                    if (neighbors < 2 or neighbors > 3)  board[r][c] = -1; //1 -> 0
                }

                else
                {
                    if (neighbors == 3)  board[r][c] = 2; // 0 -> 1
                }
            }
        }

        for (int r = 0; r < m; r++)
        {
            for (int c = 0; c < n; c++)
            {
                if (board[r][c] > 0) board[r][c] = 1;
                else board[r][c] = 0;
            }
        }
    }
};