//Recursion Bottom Up
class Solution {
public:
    int uniquePaths(int m, int n) {
        return helper(m, n);
    }

    int helper(int m, int n)
    {

        if (m == 1 || n == 1)
        {
            return 1;
        }

        return helper(m, n - 1) + helper(m - 1, n);
    }
};


//Recursion Top Down
class Solution {
public:
    int uniquePaths(int m, int n) {
        return helper(0, 0, m, n);
    }

    int helper(int i, int j, int m, int n)
    {
        if (i >= m)    return 0;
        if (j >= n)    return 0;
        if (i == m - 1 && j == n - 1)
        {
            return 1;
        }

        return helper(i + 1, j, m, n) + helper(i, j + 1, m, n);
    }

};


//Recursion with memoization
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n, -1));
        dp[m - 1][n - 1] = 1;
        return helper(0, 0, m, n, dp);
    }

    int helper(int i, int j, int m, int n, vector<vector<int>>&dp)
    {
        if (i >= m)    return 0;
        if (j >= n)    return 0;

        if (dp[i][j] != -1)    return dp[i][j];

        return dp[i][j] = helper(i + 1, j, m, n, dp) + helper(i, j + 1, m, n, dp);
    }

};


// DP
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }

        return dp[m - 1][n - 1];
    }
};

//DP
class Solution {
public:
    int uniquePaths(int m, int n) {

        vector<vector<int>>dp(m, vector<int>(n, 1));

        for (int i = m - 2; i >= 0; i--)
        {
            for (int j = n - 2; j >= 0; j--)
            {
                dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
            }
        }
        return dp[0][0];
    }
};