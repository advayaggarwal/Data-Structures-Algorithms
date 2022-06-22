//Time complexity - O(m*n)
//Space complexity - O(m*n)
class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int m, n;
    int dp[201][201];
    int longestIncreasingPath(vector<vector<int>>& matrix)
    {
        m = matrix.size();
        n = matrix[0].size();
        memset(dp, -1, sizeof(dp));
        int ans = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int count = dfs(i, j, matrix);
                ans = max(ans, count);
            }
        }

        return ans;
    }

    int dfs(int i, int j, vector<vector<int>>&matrix)
    {
        int count = 0;
        if (dp[i][j] != -1)  return dp[i][j];

        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k];
            int y = j + dy[k];
            if (x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > matrix[i][j])   count = max(count, dfs(x, y, matrix));
        }

        return dp[i][j] = 1 + count;
    }
};