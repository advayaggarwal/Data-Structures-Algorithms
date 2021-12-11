//Top Down DP
//Time complexity - O(m*n)
//Space complexity - O(m*n)
#define vvi vector<vector<int>>
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vvi dp(m, vector<int>(n, -1));

        return lcs(text1, text2, 0, 0, dp);
    }

    int lcs(string &s1, string &s2, int i, int j, vvi &dp)
    {
        if (i == s1.size() or j == s2.size())    return 0;

        if (dp[i][j] != -1)    return dp[i][j];

        if (s1[i] == s2[j])  return dp[i][j] = 1 + lcs(s1, s2, i + 1, j + 1, dp);

        int op1 = lcs(s1, s2, i + 1, j, dp);
        int op2 = lcs(s1, s2, i, j + 1, dp);

        return dp[i][j] = max(op1, op2);
    }
};


//Bottom Up DP
//Time complexity - O(m*n)
//Space complexity - O(m*n)
#define vvi vector<vector<int>>
#define vi vector<int>
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        return lcsBU(text1, text2);
    }

    int lcsBU(string &s1, string &s2)
    {
        int m = s1.size(), n = s2.size();

        vvi dp(m + 1, vi(n + 1, 0));

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s1[i - 1] == s2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];

                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[m][n];
    }
};