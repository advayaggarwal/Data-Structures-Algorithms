//Recursion
//Time complexity - O(2^m*n)
//Space complexity - O(max(m,n))
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        int m = grid.size(), n = grid[0].size();

        return helper(0, 0, m, n, grid);
    }

    int helper(int i, int j, int m, int n, vector<vector<int>>& grid)
    {
        if (i >= m or j >= n)    return INT_MAX;
        if (i == m - 1 && j == n - 1)    return grid[i][j];

        return grid[i][j] + min(helper(i + 1, j, m, n, grid), helper(i, j + 1, m, n, grid));
    }
};

//Top Down DP
//Time complexity - O(m*n)
//Space complexity - O(m*n)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>>dp(m + 1, vector<int>(n + 1, -1));
        return helper(0, 0, m, n, grid, dp);
    }

    int helper(int i, int j, int m, int n, vector<vector<int>>& grid, vector<vector<int>>&dp)
    {
        if (i >= m or j >= n)    return INT_MAX;
        if (i == m - 1 && j == n - 1)    return grid[i][j];
        if (dp[i][j] != -1)  return dp[i][j];

        return dp[i][j] = grid[i][j] + min(helper(i + 1, j, m, n, grid, dp), helper(i, j + 1, m, n, grid, dp));
    }
};

//Bottom Up DP
//Time complexity - O(m*n)
//Space complexity - O(m*n)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)    dp[i][j] = grid[i][j];
                else
                {
                    int up = grid[i][j], left = grid[i][j];

                    if (i > 0)   up += dp[i - 1][j];
                    else up = INT_MAX;
                    if (j > 0)   left += dp[i][j - 1];
                    else left = INT_MAX;

                    dp[i][j] = min(up, left);
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};

//Bottom Up DP
//Time complexity - O(m*n)
//Space complexity - O(1)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 1; i < n; i++)  grid[0][i] += grid[0][i - 1];
        for (int i = 1; i < m; i++)  grid[i][0] += grid[i - 1][0];

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }

        return grid[m - 1][n - 1];
    }
};