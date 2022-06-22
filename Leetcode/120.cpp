//Recursion
//Time complexity - O(2^n)
//Space complexity - O(n)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle)
    {
        int n = triangle.size();
        return helper(0, 0, n, triangle);
    }

    int helper(int i, int j, int n, vector<vector<int>>&triangle)
    {
        if (i == n - 1)  return triangle[i][j];

        int op1 = helper(i + 1, j, n, triangle);
        int op2 = helper(i + 1, j + 1, n, triangle);

        return triangle[i][j] + min(op1, op2);
    }
};

//Top Down DP
//Time complexity - O(n^2)
//Space complexity - O(n^2)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle)
    {
        int n = triangle.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));

        return helper(0, 0, n, triangle, dp);
    }

    int helper(int i, int j, int n, vector<vector<int>>& triangle, vector<vector<int>>&dp)
    {
        if (i == n - 1)  return triangle[i][j];

        if (dp[i][j] != -1)  return dp[i][j];

        int op1 = helper(i + 1, j, n, triangle, dp);
        int op2 = helper(i + 1, j + 1, n, triangle, dp);

        return dp[i][j] = triangle[i][j] + min(op1, op2);
    }
};

//Bottom Up DP
//Time complexity - O(n^2)
//Space complexity - O(n^2)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle)
    {
        int n = triangle.size();
        vector<vector<int>>dp(n + 1, vector<int>(n + 1));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j <= i; j++)
            {
                dp[i][j] = triangle[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1]);
            }
        }

        return dp[0][0];
    }
};

//Bottom Up DP with space optimisation, to fill current row, we only need next row
//Time complexity - O(n^2)
//Space complexity - O(n)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle)
    {
        int n = triangle.size();
        vector<int>curr(n + 1), next(n + 1);

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j <= i; j++)
            {
                curr[j] = triangle[i][j] + min(next[j], next[j + 1]);
            }

            next = curr;
        }

        return curr[0];
    }
};


//Bottom Up DP by using triangle vector as DP vector
//Time complexity - O(n^2)
//Space complexity - O(1)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle)
    {
        int n = triangle.size();

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = 0; j <= i; j++)
            {
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }

        return triangle[0][0];
    }
};