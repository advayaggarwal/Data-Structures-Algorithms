//Time complexity - O(m*n)
//Space complexity - O(m*n)
class Solution {
public:
    int minDistance(string word1, string word2) {
        int lcs_length = lcs(word1, word2);

        return word1.size() + word2.size() - 2 * lcs_length;
    }

    int lcs(string &word1, string &word2)
    {
        int m = word1.size(), n = word2.size();

        vector<vector<int>>dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }

                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[m][n];
    }
};