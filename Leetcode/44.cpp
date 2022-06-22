//Recursion
//Time complexity - O(3^(m*n))
//Space complexity - O(m+n)
class Solution {
public:
    bool isMatch(string s, string p)
    {
        int m = s.size(), n = p.size();
        return helper(m - 1, n - 1, s, p);
    }

    bool helper(int i, int j, string &s, string &p)
    {
        if (i < 0 && j < 0)  return true; //both empty
        if (i >= 0 && j < 0)  return false; //pattern finished but string s didn't, therefore in no way we can match them
        if (i < 0 && j >= 0) //string s finished but pattern p didn't, therefore remaining p should be all *
        {
            while (j >= 0)
            {
                if (p[j--] != '*') return false;
            }

            return true;
        }

        if (s[i] == p[j] or p[j] == '?')    return helper(i - 1, j - 1, s, p);
        else if (p[j] == '*') return helper(i - 1, j, s, p) or helper(i, j - 1, s, p);

        return false;
    }
};

//Top Down DP
//Time complexity - O(m*n)
//Space complexity - O(m*n)
class Solution {
public:
    bool isMatch(string s, string p)
    {
        int m = s.size(), n = p.size();
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return helper(m - 1, n - 1, s, p, dp);
    }

    bool helper(int i, int j, string &s, string &p, vector<vector<int>>&dp)
    {
        if (i < 0 && j < 0)  return true; //both empty
        if (i >= 0 && j < 0)  return false; //pattern finished but string s didn't, therefore in no way we can match them
        if (i < 0 && j >= 0) //string s finished but pattern p didn't, therefore remaining p should be all *
        {
            while (j >= 0)
            {
                if (p[j--] != '*') return false;
            }

            return true;
        }

        if (dp[i][j] != -1)  return dp[i][j];

        if (s[i] == p[j] or p[j] == '?')    return dp[i][j] = helper(i - 1, j - 1, s, p, dp);
        else if (p[j] == '*') return dp[i][j] = helper(i - 1, j, s, p, dp) or helper(i, j - 1, s, p, dp);

        return dp[i][j] = false;
    }
};

//Bottom Up DP
//Time complexity - O(m*n)
//Space complexity - O(m*n)
class Solution {
public:
    bool isMatch(string s, string p)
    {
        int m = s.size(), n = p.size();
        vector<vector<bool>>dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;

        for (int i = 1; i <= n; i++)
        {
            if (p[i - 1] == '*')   dp[0][i] = true;
            else break;
        }

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s[i - 1] == p[j - 1] or p[j - 1] == '?')    dp[i][j] = dp[i - 1][j - 1];
                else if (p[j - 1] == '*')  dp[i][j] = dp[i - 1][j] or dp[i][j - 1];
            }
        }

        return dp[m][n];
    }
};

//Bottom Up DP with space optimisation
//Time complexity - O(m*n)
//Space complexity - O(n)
class Solution {
public:
    bool isMatch(string s, string p)
    {
        int m = s.size(), n = p.size();
        vector<bool>prev(n + 1), curr(n + 1);
        prev[0] = true;

        for (int i = 1; i <= n; i++)
        {
            if (p[i - 1] == '*')   prev[i] = true;
            else break;
        }

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s[i - 1] == p[j - 1] or p[j - 1] == '?')    curr[j] = prev[j - 1];
                else if (p[j - 1] == '*')  curr[j] = prev[j] or curr[j - 1];
                else curr[j] = false;
            }

            prev = curr;
        }

        return prev[n];
    }
};