//Top Down DP
//Time complexity - O(m*n)
//Space complexity - O(m*n)
class Solution {
public:
    int m, n;
    bool isInterleave(string s1, string s2, string s3)
    {
        m = s1.size(), n = s2.size();
        if (m + n != s3.size())  return false;
        vector<vector<int>>dp(m + 1, vector<int>(n + 1, -1));
        return helper(0, 0, 0, s1, s2, s3, dp);
    }

    bool helper(int i, int j, int k, string &s1, string &s2, string &s3, vector<vector<int>>&dp)
    {
        if (i == m && j == n)    return k == s3.size();
        if (dp[i][j] != -1)  return dp[i][j];

        bool op1 = false, op2 = false;

        if (i < m && s1[i] == s3[k])  op1 = helper(i + 1, j, k + 1, s1, s2, s3, dp);
        if (j < n && s2[j] == s3[k])  op2 = helper(i, j + 1, k + 1, s1, s2, s3, dp);

        return dp[i][j] = op1 || op2;
    }
};