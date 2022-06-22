//Time complexity - O(m*n)
//Space complexity - O(m*n), auxiliary stack space
class Solution {
public:
    int dx[4] = { -1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int numEnclaves(vector<vector<int>>& grid)
    {
        int m = grid.size(), n = grid[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 or j == 0 or i == m - 1 or j == n - 1)
                {
                    if (grid[i][j] == 1) dfs(i, j, m, n, grid);
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1) ans++;
            }
        }

        return ans;
    }

    void dfs(int i, int j, int m, int n, vector<vector<int>>& grid)
    {
        grid[i][j] = 0;

        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k];
            int y = j + dy[k];

            if (x > 0 && y > 0 && x < m - 1 && y < n - 1 && grid[x][y] == 1)   dfs(x, y, m, n, grid);
        }
    }
};