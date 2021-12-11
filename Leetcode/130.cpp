//Time complexity - O()
//Space complexity - O()
class Solution {
public:

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    void solve(vector<vector<char>>& board)
    {
        int m = board.size(), n = board[0].size();

        vector<vector<bool>>visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++)
        {
            if (!visited[i][0] && board[i][0] == 'O')
            {
                dfs(i, 0, m, n, visited, board);
            }

            if (!visited[i][n - 1] && board[i][n - 1] == 'O')
            {
                dfs(i, n - 1, m, n, visited, board);
            }

        }

        for (int j = 0; j < n; j++)
        {
            if (!visited[0][j] && board[0][j] == 'O')
            {
                dfs(0, j, m, n, visited, board);
            }

            if (!visited[m - 1][j] && board[m - 1][j] == 'O')
            {
                dfs(m - 1, j, m, n, visited, board);
            }
        }


        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == '#')  board[i][j] = 'O';
                else if (board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }

    void dfs(int i, int j, int m, int n, vector<vector<bool>>&visited, vector<vector<char>>& board)
    {
        visited[i][j] = true;
        board[i][j] = '#';
        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k];
            int y = j + dy[k];

            if (x >= 0 && x < m && y >= 0 && y < n && !visited[x][y] && board[x][y] == 'O')
            {
                board[x][y] = '#';
                dfs(x, y, m, n, visited, board);
            }
        }
    }
};