//Time complexity - O(m*n)
//Space complexity - O(m*n)
class Solution {
public:
    int dx[4] = { -1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    int closedIsland(vector<vector<int>>& grid)
    {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;

        vector<vector<bool>>visited(m, vector<bool>(n, false));

        //Boundary DFS, converting land to water
        for (int i = 0; i < m; i++) //marking boundary 0's as 1
        {
            if (!visited[i][0] && grid[i][0] == 0)   dfs(i, 0, m, n, grid, visited);
            if (!visited[i][n - 1] && grid[i][n - 1] == 0)   dfs(i, n - 1, m, n, grid, visited);
        }

        for (int j = 0; j < n; j++) //marking boundary 0's as 1
        {
            if (!visited[0][j] && grid[0][j] == 0)   dfs(0, j, m, n, grid, visited);
            if (!visited[m - 1][j] && grid[m - 1][j] == 0)   dfs(m - 1, j, m, n, grid, visited);
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visited[i][j] && grid[i][j] == 0)
                {
                    dfs(i, j, m, n, grid, visited);
                    ans++;
                }
            }
        }

        return ans;
    }

    void dfs(int i, int j, int m, int n, vector<vector<int>>& grid, vector<vector<bool>>&visited)
    {
        visited[i][j] = true;
        grid[i][j] = 1;

        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k];
            int y = j + dy[k];

            if (x > 0 && y > 0 && x < m - 1 && y < n - 1 && !visited[x][y] && grid[x][y] == 0)   dfs(x, y, m, n, grid, visited);
        }
    }
};

//No need of separate visited vector, marking grid as 1 if visited
class Solution {
public:
    int dx[4] = { -1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    int closedIsland(vector<vector<int>>& grid)
    {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;

        for (int i = 0; i < m; i++) //marking boundary 0's as 1
        {
            if (grid[i][0] == 0)   dfs(i, 0, m, n, grid);
            if (grid[i][n - 1] == 0)   dfs(i, n - 1, m, n, grid);
        }

        for (int j = 0; j < n; j++) //marking boundary 0's as 1
        {
            if (grid[0][j] == 0)   dfs(0, j, m, n, grid);
            if (grid[m - 1][j] == 0)   dfs(m - 1, j, m, n, grid);
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                {
                    dfs(i, j, m, n, grid);
                    ans++;
                }
            }
        }

        return ans;
    }

    void dfs(int i, int j, int m, int n, vector<vector<int>>& grid)
    {
        grid[i][j] = 1;

        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k];
            int y = j + dy[k];

            if (x > 0 && y > 0 && x < m - 1 && y < n - 1 && grid[x][y] == 0)   dfs(x, y, m, n, grid);
        }
    }
};