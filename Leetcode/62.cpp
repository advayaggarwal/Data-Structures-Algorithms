//Recursion Top Down
//Time complexity - O(2^(m*n))
class Solution {
public:
    int uniquePaths(int m, int n) {

        if (m == 1 or n == 1)   return 1;

        return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
    }
};

//Recursion Bottom Up
class Solution {
public:
    int uniquePaths(int m, int n) {
        return helper(0, 0, m, n);
    }

    int helper(int i, int j, int m, int n)
    {
        if (i >= m)    return 0;
        if (j >= n)    return 0;
        if (i == m - 1 && j == n - 1)   return 1;

        return helper(i + 1, j, m, n) + helper(i, j + 1, m, n);
    }
};


//Recursion with memoization(Top Down DP)
//Time complexity - O(m*n)
//Space complexity - O(m*n)
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return helper(0, 0, m, n, dp);
    }

    int helper(int i, int j, int m, int n, vector<vector<int>>&dp)
    {
        if (i == m - 1 or j == n - 1)    return 1;

        if (dp[i][j] != -1)    return dp[i][j];

        return dp[i][j] = helper(i + 1, j, m, n, dp) + helper(i, j + 1, m, n, dp);
    }
};


//Bottom Up DP
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

//Bottom Up DP with space optimisation
//Time complexity - O(m*n)
//Space complexity - O(n)
class Solution {
public:
    int uniquePaths(int m, int n)
    {
        vector<int>prev(n, 1), curr(n, 1);

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                curr[j] = curr[j - 1] + prev[j];
            }
            prev = curr;
        }

        return curr[n - 1];
    }
};

//Bottom Up DP
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
        int N = n + m - 2; //(n-1) + (m-1) i.e. we have to take m-1 steps downwards and n-1 steps rightwards
        //ans = (N)C(n-1) or (N)C(m-1)

        int ans = 1;
        int r = m - 1;
        for (int i = 1; i <= r; i++)
        {
            ans = ans * 1LL * (N - r + i) / i;
            /*
            eg- 10C3 = (8/1)*(9/2)*(10/3)
            Don't do (10/1)*(9/2)*(8/3)
            Mathematically both are same but the 2nd one will give integer overflow
            */
        }

        return ans;
    }
};