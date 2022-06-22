//Top Down DP
//Time complexity - O(m*n)
//Space complexity - O(m*n)
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>>dp(m, vector<int>(n, -1));

        return helper(m - 1, n - 1, obstacleGrid, dp);
    }

    int helper(int m, int n, vector<vector<int>>& obstacleGrid, vector<vector<int>>&dp)
    {
        if (m == 0 && n == 0)    return obstacleGrid[m][n] == 0;
        if (m < 0 or n < 0 or obstacleGrid[m][n] == 1)  return 0;
        if (dp[m][n] != -1)  return dp[m][n];

        return dp[m][n] = helper(m - 1, n, obstacleGrid, dp) + helper(m, n - 1, obstacleGrid, dp);
    }
};

//Bottom Up DP
//Time complexity - O(m*n)
//Space complexity - O(m*n)
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>>dp(m, vector<int>(n));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)   dp[i][j] = 1;
                else if (obstacleGrid[i][j] == 0)
                {
                    int up = 0, left = 0;
                    if (i > 0)   up = dp[i - 1][j];
                    if (j > 0)   left = dp[i][j - 1];

                    dp[i][j] = up + left;
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};