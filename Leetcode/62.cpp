//Recursion Bottom Up
class Solution {
public:
    int uniquePaths(int m, int n) {

        if (m == 1 or n == 1)   return 1;

        return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
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
//Time complexity - O(m*n)
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


//DP
//Time complexity - O(m*n)
//Space complexity - O(m*n)
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
//Time complexity - O(m*n)
//Space complexity - O(m*n)
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

//Combinatorics
//Time complexity - O(m) or O(n)
//Space complexity - O(1)
class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = n + m - 2;
        //ans = (N)C(n-1) or (N)C(m-1)

        double ans = 1;
        int r = m - 1;
        for (int i = 1; i <= r; i++)
        {
            ans = ans * (N - r + i) / i;
        }
        return (int)ans;
    }
};
