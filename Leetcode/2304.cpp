//Recursion
//Time complexity - O(n^(m*n) * n), every cell is making n function calls, each function call is O(n)
//Space complexity - O(m*n)
class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost)
    {
        int m = grid.size(), n = grid[0].size();
        int ans = INT_MAX;
        for (int i = 0; i < n; i++)    ans = min(ans, helper(0, i, m, n, grid, moveCost));
        return ans;
    }

    int helper(int i, int j, int m, int n, vector<vector<int>>& grid, vector<vector<int>>& moveCost)
    {
        if (i == m - 1)    return grid[i][j];
        int ans = INT_MAX;
        for (int k = 0; k < n; k++)    ans = min(ans, grid[i][j] + moveCost[grid[i][j]][k] + helper(i + 1, k, m, n, grid, moveCost));
        return ans;
    }
};

//Top Down DP
//Time complexity - O(m*n*n)
//Space complexity - O(m*n)
class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n, -1));
        int ans = INT_MAX;
        for (int i = 0; i < n; i++)    ans = min(ans, helper(0, i, m, n, grid, moveCost, dp));
        return ans;
    }

    int helper(int i, int j, int m, int n, vector<vector<int>>& grid, vector<vector<int>>& moveCost, vector<vector<int>>&dp)
    {
        if (i == m - 1)    return grid[i][j];
        if (dp[i][j] != -1)  return dp[i][j];
        int ans = INT_MAX;
        for (int k = 0; k < n; k++)    ans = min(ans, grid[i][j] + moveCost[grid[i][j]][k] + helper(i + 1, k, m, n, grid, moveCost, dp));
        return dp[i][j] = ans;
    }
};

//Bottom Up DP
//Time complexity - O(m*n*n)
//Space complexity - O(m*n)
class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<long long>>dp(m, vector<long long>(n));

        for (int j = 0; j < n; j++)  dp[m - 1][j] = grid[m - 1][j];

        for (int i = m - 2; i >= 0; i--)
        {
            for (int j = 0; j < n; j++)
            {
                long long mini = INT_MAX;
                for (int k = 0; k < n; k++)
                {
                    mini = min(mini, dp[i + 1][k] + moveCost[grid[i][j]][k]);
                }
                dp[i][j] = mini + grid[i][j];
            }
        }

        return *min_element(dp[0].begin(), dp[0].end());
    }
};