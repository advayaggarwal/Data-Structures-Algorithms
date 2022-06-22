//Top Down DP
//Time complexity - O(9*n*m*m)
//Space complexity - O(n*m*m)
class Solution {
public:
    int dp[70][70][70];
    int cherryPickup(vector<vector<int>>& grid)
    {
        int n = grid.size(), m = grid[0].size();
        memset(dp, -1, sizeof dp);

        return helper(grid, n, m, 0, 0, m - 1);
    }

    int helper(vector<vector<int>>& grid, int n, int m, int r, int c1, int c2)
    {
        if (r<0 or r >= n or c1<0 or c1 >= m or c2<0 or c2 >= m)   return 0;

        if (dp[r][c1][c2] != -1) return dp[r][c1][c2];

        int maxCherries = 0;

        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                int nc1 = c1 + i;
                int nc2 = c2 + j;
                maxCherries = max(maxCherries, helper(grid, n, m, r + 1, nc1, nc2));
            }
        }

        if (c1 == c2)    maxCherries += grid[r][c1];
        else maxCherries += grid[r][c1] + grid[r][c2];

        return dp[r][c1][c2] = maxCherries;
    }
};

//Bottom Up DP
//Time complexity - O(9*n*m*m)
//Space complexity - O(n*m*m)
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>>dp(m, vector<vector<int>>(n, vector<int>(n)));

        for (int j1 = 0; j1 < n; j1++)
        {
            for (int j2 = 0; j2 < n; j2++)
            {
                if (j1 != j2)  dp[m - 1][j1][j2] = grid[m - 1][j1] + grid[m - 1][j2];
                else dp[m - 1][j1][j2] = grid[m - 1][j1];
            }
        }

        for (int i = m - 2; i >= 0; i--)
        {
            for (int j1 = 0; j1 < n; j1++)
            {
                for (int j2 = 0; j2 < n; j2++)
                {
                    int ans = 0;
                    for (int dj1 = -1; dj1 <= 1; dj1++)
                    {
                        for (int dj2 = -1; dj2 <= 1; dj2++)
                        {
                            int c1 = j1 + dj1;
                            int c2 = j2 + dj2;
                            if (c1 >= 0 && c1 < n && c2 >= 0 && c2 < n)  ans = max(ans, dp[i + 1][c1][c2]);
                        }
                    }
                    dp[i][j1][j2] = ans + grid[i][j1];
                    if (j1 != j2)    dp[i][j1][j2] += grid[i][j2];
                }
            }
        }

        return dp[0][0][n - 1];
    }
};