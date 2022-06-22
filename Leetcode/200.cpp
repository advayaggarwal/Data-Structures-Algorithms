//Time complexity - O(m*n)
//Space complexity - O(m*n)
class Solution {
public:
    int dx[4] = { -1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    int numIslands(vector<vector<char>>& grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>>visited(m, vector<bool>(n, false));

        int count = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1' && !visited[i][j])
                {
                    count++;
                    dfs(i, j, m, n, visited, grid);
                }
            }
        }

        return count;
    }

    void dfs(int i, int j, int m, int n, vector<vector<bool>>&visited, vector<vector<char>>& grid)
    {
        visited[i][j] = true;

        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k];
            int y = j + dy[k];

            if (x >= 0 && x < m && y >= 0 && y < n && !visited[x][y] && grid[x][y] == '1') dfs(x, y, m, n, visited, grid);
        }
    }
};