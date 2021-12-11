class Solution {
public:
    int dx[4] = { -1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    bool exist(vector<vector<char>>& board, string word)
    {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>>visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == word[0])
                {
                    if (dfs(i, j, m, n, visited, board, 1, word)) return true;
                }
            }
        }

        return false;
    }

    bool dfs(int i, int j, int m, int n, vector<vector<bool>>&visited, vector<vector<char>>& board, int index, string word)
    {
        visited[i][j] = true;

        if (index == word.size())    return true;

        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k];
            int y = j + dy[k];

            if (x >= 0 && x < m && y >= 0 && y < n && !visited[x][y] && board[x][y] == word[index])
            {
                if (dfs(x, y, m, n, visited, board, index + 1, word))  return true;
            }
        }

        visited[i][j] = false; //backtrack

        return false;
    }

};