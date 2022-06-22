//Top Down DP - LCS
//Time complexity - O(m*n)
//Space complexity - O(m*n)
class Solution {
public:
    int minDistance(string word1, string word2)
    {
        vector<vector<int>>dp(word1.size(), vector<int>(word2.size(), -1));
        int Lcs = lcs(0, 0, word1, word2, dp);
        return word1.size() + word2.size() - 2 * Lcs;
    }

    int lcs(int i, int j, string &s1, string &s2, vector<vector<int>>&dp)
    {
        if (i == s1.size() or j == s2.size())    return 0;
        if (dp[i][j] != -1)  return dp[i][j];

        if (s1[i] == s2[j])  return dp[i][j] = 1 + lcs(i + 1, j + 1, s1, s2, dp);
        return dp[i][j] = max(lcs(i + 1, j, s1, s2, dp), lcs(i, j + 1, s1, s2, dp));
    }
};

//Bottom Up DP - LCS
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

//Without LCS Top Down DP
//Time complexity - O(m*n)
//Space complexity - O(m*n)
class Solution {
public:
    int minDistance(string word1, string word2)
    {
        vector<vector<int>>dp(word1.size(), vector<int>(word2.size(), -1));
        //dp[i][j] denotes min steps required to make word1[i...m] and word2[j...n] same
        return helper(0, 0, word1, word2, dp);
    }

    int helper(int i, int j, string &s1, string &s2, vector<vector<int>>&dp)
    {
        if (i == s1.size() or j == s2.size())    return s1.size() - i + s2.size() - j;
        if (dp[i][j] != -1)  return dp[i][j];

        if (s1[i] == s2[j])  return dp[i][j] = helper(i + 1, j + 1, s1, s2, dp);
        return dp[i][j] = 1 + min(helper(i + 1, j, s1, s2, dp), helper(i, j + 1, s1, s2, dp));
    }
};

//Without LCS Bottom Up DP
//Time complexity - O(m*n)
//Space complexity - O(m*n)
class Solution {
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.size(), n = word2.size();
        vector<vector<int>>dp(m + 1, vector<int>(n + 1));

        for (int i = 0; i <= n; i++) dp[m][i] = n - i;
        for (int i = 0; i <= m; i++) dp[i][n] = m - i;

        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (word1[i] == word2[j])  dp[i][j] = dp[i + 1][j + 1];
                else dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j + 1]);
            }
        }

        return dp[0][0];
    }
};

//Without LCS Bottom Up DP with space optimisation
//Time complexity - O(m*n)
//Space complexity - O(n)
class Solution {
public:
    int minDistance(string& word1, string& word2)
    {
        int m = word1.size(), n = word2.size();
        vector<int>prev(n + 1), curr(n + 1);
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (!i || !j) curr[j] = i + j; // if one word == "", all other characters of other word need to be deleted
                else
                {
                    if (word1[i - 1] == word2[j - 1])   curr[j] = prev[j - 1];
                    else curr[j] = 1 + min(prev[j], curr[j - 1]);
                }
            }

            prev = curr;
        }

        return prev[n];
    }
};