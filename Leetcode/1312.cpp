//Time complexity - O(n^2)
//Space complexity - O(n^2)
class Solution {
public:
    int minInsertions(string s) {
        string s1 = s;
        reverse(s1.begin(), s1.end());

        int lcs = LCS(s, s1);

        return s.size() - lcs;
    }

    int LCS(string &s, string &s1)
    {
        int m = s.size(), n = s1.size();

        vector<vector<int>>dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s[i - 1] == s1[j - 1])   dp[i][j] = 1 + dp[i - 1][j - 1];

                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[m][n];
    }
};