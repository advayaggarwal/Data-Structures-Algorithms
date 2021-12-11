//Top Down DP
//Time complexity - O(m*n)
//Space complexity - O(m*n)
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[m - 1][n - 1] == 1 or obstacleGrid[0][0] == 1)   return 0;
        vector<vector<int>>dp(m + 1, vector<int>(n + 1, -1));

        return helper(m, n, obstacleGrid, dp);
    }

    int helper(int m, int n, vector<vector<int>>& obstacleGrid, vector<vector<int>>&dp)
    {
        if (m < 1 or n < 1)    return 0;

        if (m == 1 && n == 1)
        {
            return  obstacleGrid[m - 1][n - 1] == 1 ? 0 : 1;
        }

        if (dp[m][n] != -1)  return dp[m][n];

        int op1, op2;

        if (m >= 2 && n >= 1 && obstacleGrid[m - 2][n - 1] == 1)   op1 = 0;
        else op1 = helper(m - 1, n, obstacleGrid, dp);

        if (m >= 1 && n >= 2 && obstacleGrid[m - 1][n - 2] == 1)   op2 = 0;
        else    op2 = helper(m, n - 1, obstacleGrid, dp);

        return dp[m][n] = op1 + op2;
    }
};

//Bottom Up DP
//Time complexity - O(m*n)
//Space complexity - O(m*n)
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>>dp(m, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
        {
            if (obstacleGrid[0][i] == 0) dp[0][i] = 1;
            else break;
        }

        for (int i = 0; i < m; i++)
        {
            if (obstacleGrid[i][0] == 0) dp[i][0] = 1;
            else break;
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (obstacleGrid[i][j] == 1) dp[i][j] = 0;
                else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};