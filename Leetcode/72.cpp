//Recursion
//Time complexity - O(3^(m*n)), exponential
//Space complexity - O(m*n)
class Solution {
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.size(), n = word2.size();
        return helper(0, 0, m, n, word1, word2);
    }

    int helper(int i, int j, int m, int n, string &s1, string &s2)
    {
        if (i == m)    return n - j;

        if (j == n)    return m - i;

        if (s1[i] == s2[j])  return helper(i + 1, j + 1, m, n, s1, s2);

        else
        {
            int op1 = helper(i + 1, j + 1, m, n, s1, s2); //replace
            int op2 = helper(i, j + 1, m, n, s1, s2); //insert
            int op3 = helper(i + 1, j, m, n, s1, s2); //delete

            return 1 + min({op1, op2, op3});
        }
    }
};

//Top Down DP
//Time complexity - O(m*n)
//Space complexity - O(m*n)
class Solution {
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.size(), n = word2.size();
        vector<vector<int>>dp(m + 1, vector<int>(n + 1, -1));
        return helper(0, 0, m, n, word1, word2, dp);
    }

    int helper(int i, int j, int m, int n, string &s1, string &s2, vector<vector<int>>&dp)
    {
        if (i == m)    return n - j;

        if (j == n)    return m - i;

        if (dp[i][j] != -1)  return dp[i][j];

        if (s1[i] == s2[j])  return dp[i][j] = helper(i + 1, j + 1, m, n, s1, s2, dp);

        else
        {
            int op1 = helper(i + 1, j + 1, m, n, s1, s2, dp); //replace
            int op2 = helper(i, j + 1, m, n, s1, s2, dp); //insert
            int op3 = helper(i + 1, j, m, n, s1, s2, dp); //delete

            return dp[i][j] = 1 + min({op1, op2, op3});
        }
    }
};


//Bottom Up DP
//Time complexity - O(m*n)
//Space complexity - O(m*n)
class Solution {
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.size(), n = word2.size();
        vector<vector<int>>dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (i == 0) dp[i][j] = j; //one string is empty, so we have to insert length no of chars to make them equal
                else if (j == 0)    dp[i][j] = i; //one string is empty, so we have to insert length no of chars to make them equal
                else
                {
                    if (word1[i - 1] == word2[j - 1])    dp[i][j] = dp[i - 1][j - 1];

                    else    dp[i][j] = 1 + min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}); //{replace, delete, insert}
                }
            }
        }

        return dp[m][n];
    }
};