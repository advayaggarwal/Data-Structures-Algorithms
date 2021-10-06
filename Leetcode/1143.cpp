//Top Down DP

#define vvi vector<vector<int>>
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size();
        vvi dp(n1, vector<int>(n2, -1));

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

#define vvi vector<vector<int>>
#define vi vector<int>
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        return lcsBU(text1, text2);
    }

    int lcsBU(string &s1, string &s2)
    {
        int n1 = s1.size(), n2 = s2.size();

        vvi dp(n1 + 1, vi(n2 + 1, 0));

        for (int i = 1; i <= n1; i++)
        {
            for (int j = 1; j <= n2; j++)
            {
                if (s1[i - 1] == s2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];

                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[n1][n2];
    }

};