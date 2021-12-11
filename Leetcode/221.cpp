//Bottom Up DP
//Time complexity - O(m*n)
//Space complexity - O(m*n)
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>>dp(m, vector<int>(n)); //dp[i][j] -> best square ending at (i,j)
        int mx = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == '1')
                {
                    dp[i][j] = 1;
                    if (i > 0 && j > 0)
                    {
                        dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
                    }

                    mx = max(mx, dp[i][j]);
                }
            }
        }

        return mx * mx;
    }
};