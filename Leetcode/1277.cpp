/*
dp[i][j] means the size of biggest square with matrix[i][j] as bottom-right corner.
dp[i][j] also means the number of squares with matrix[i][j] as bottom-right corner.
*/

//Bottom Up DP
//Time complexity - O(m*n)
//Space complexity - O(m*n)
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix)
    {
        int m = matrix.size(), n = matrix[0].size(), ans = 0;
        vector<vector<int>>dp(m, vector<int>(n));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 or j == 0)    dp[i][j] = matrix[i][j];
                else if (matrix[i][j] == 1) dp[i][j] = 1 + min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});

                ans += dp[i][j];
            }
        }

        return ans;
    }
};


//Bottom Up DP with space optimisation
//Time complexity - O(m*n)
//Space complexity - O(n)
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix)
    {
        int m = matrix.size(), n = matrix[0].size(), ans = 0;
        vector<int>prev(n);

        for (int i = 0; i < m; i++)
        {
            vector<int>curr(n);
            for (int j = 0; j < n; j++)
            {
                if (i == 0 or j == 0)    curr[j] = matrix[i][j];
                else if (matrix[i][j] == 1) curr[j] = 1 + min({prev[j - 1], prev[j], curr[j - 1]});

                ans += curr[j];
            }

            prev = curr;
        }

        return ans;
    }
};