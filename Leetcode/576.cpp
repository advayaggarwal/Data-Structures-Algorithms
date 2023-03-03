//Time complexity - O(m*n*maxMove)
//Space complexity - O(m*n*maxMove)
class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = { -1, 1, 0, 0};
    int mod = 1e9 + 7;
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        vector<vector<vector<int>>>dp(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
        return helper(m, n, maxMove, startRow, startColumn, dp);
    }

    int helper(int m, int n, int maxMove, int startRow, int startColumn, vector<vector<vector<int>>>&dp)
    {
        if (maxMove < 0) return 0;
        if (startRow >= m or startColumn >= n or startRow < 0 or startColumn < 0)   return 1;
        if (dp[startRow][startColumn][maxMove] != -1) return dp[startRow][startColumn][maxMove];

        int ans = 0;
        for (int k = 0; k < 4; k++)
        {
            int i = startRow + dx[k];
            int j = startColumn + dy[k];
            ans = (ans + helper(m, n, maxMove - 1, i, j, dp)) % mod;
        }

        return dp[startRow][startColumn][maxMove] = ans;
    }
};

//Time complexity - O(m*n*maxMove)
//Space complexity - O(m*n)
class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = { -1, 1, 0, 0};
        vector<vector<int>>dp(m, vector<int>(n));
        int mod = 1e9 + 7;
        dp[startRow][startColumn] = 1;
        int count = 0;

        for (int move = 1; move <= maxMove; move++)
        {
            vector<vector<int>>temp(m, vector<int>(n));
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    for (int k = 0; k < 4; k++)
                    {
                        int ni = i + dx[k];
                        int nj = j + dy[k];
                        if (ni < 0 or ni >= m or nj < 0 or nj >= n)  count = (count + dp[i][j]) % mod;
                        else    temp[ni][nj] = (temp[ni][nj] + dp[i][j]) % mod;
                    }
                }
            }

            dp = temp;
        }

        return count;
    }
};