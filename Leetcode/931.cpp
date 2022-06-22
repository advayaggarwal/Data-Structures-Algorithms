//Recursion
//Time complexity - O(3^n)
//Space complexity - O(n)
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix)
    {
        int n = matrix.size();
        int ans = INT_MAX;

        for (int c = 0; c < n; c++)
        {
            ans = min(ans, helper(0, c, n, matrix)); //we can start from any column
        }

        return ans;
    }

    int helper(int i, int j, int n, vector<vector<int>>& matrix)
    {
        if (i == n)  return 0;
        if (j<0 or j >= n) return INT_MAX;

        int op1 = helper(i + 1, j - 1, n, matrix);
        int op2 = helper(i + 1, j, n, matrix);
        int op3 = helper(i + 1, j + 1, n, matrix);

        return matrix[i][j] + min(op1, min(op2, op3));
    }
};


//Top Down DP
//Time complexity - O(n^2)
//Space complexity - O(n^2)
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix)
    {
        int n = matrix.size();
        int ans = INT_MAX;

        vector<vector<int>>dp(n, vector<int>(n, -1));

        for (int c = 0; c < n; c++)
        {
            ans = min(ans, helper(0, c, n, matrix, dp)); //we can start from any column
        }

        return ans;
    }

    int helper(int i, int j, int n, vector<vector<int>>& matrix, vector<vector<int>>&dp)
    {
        if (i == n)  return 0;
        if (j<0 or j >= n) return INT_MAX;

        if (dp[i][j] != -1)  return dp[i][j];

        int op1 = helper(i + 1, j - 1, n, matrix, dp);
        int op2 = helper(i + 1, j, n, matrix, dp);
        int op3 = helper(i + 1, j + 1, n, matrix, dp);

        return dp[i][j] = matrix[i][j] + min(op1, min(op2, op3));
    }
};

//Bottom Up DP
//Time complexity - O(n^2)
//Space complexity - O(1)
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix)
    {
        int n = matrix.size();

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = 0; j < n; j++)
            {
                int temp = matrix[i + 1][j];
                if (j + 1 < n) temp = min(temp, matrix[i + 1][j + 1]);
                if (j - 1 >= 0) temp = min(temp, matrix[i + 1][j - 1]);
                matrix[i][j] += temp;
            }
        }

        return *min_element(matrix[0].begin(), matrix[0].end());
    }
};