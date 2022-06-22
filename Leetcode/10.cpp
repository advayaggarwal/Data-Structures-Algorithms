//Recursion
//Time complexity - O(2^(m*n))
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
        if (i < 0 && j < 0)  return true;
        if (i >= 0 && j < 0) return false;
        if (i < 0 && j >= 0) //number of remaining chars should be even & half of them should be *, so it can be mapped to empty string
        {
            int count = 0, len = j + 1;
            if (len & 1) return false;
            while (j >= 0)
            {
                if (p[j--] == '*') count++;
            }

            return count == len / 2;
        }

        if (s[i] == p[j] or p[j] == '.') return helper(i - 1, j - 1, s, p);
        else if (p[j] == '*') return helper(i, j - 2, s, p) or ((s[i] == p[j - 1] or p[j - 1] == '.') && helper(i - 1, j, s, p));

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
        if (i < 0 && j < 0)  return true;
        if (i >= 0 && j < 0) return false;
        if (i < 0 && j >= 0) //number of remaining chars should be even & half of them should be *, so it can be mapped to empty string
        {
            int count = 0, len = j + 1;
            if (len & 1) return false;
            while (j >= 0)
            {
                if (p[j--] == '*') count++;
            }

            return count == len / 2;
        }
        if (dp[i][j] != -1)  return dp[i][j];

        if (s[i] == p[j] or p[j] == '.') return dp[i][j] = helper(i - 1, j - 1, s, p, dp);
        else if (p[j] == '*') return dp[i][j] = helper(i, j - 2, s, p, dp) or ((s[i] == p[j - 1] or p[j - 1] == '.') && helper(i - 1, j, s, p, dp));

        return dp[i][j] = false;
    }
};

//Bottom Up DP, simply converting top down to bottom up
//Time complexity - O(m*n)
//Space complexity - O(m*n)
class Solution {
public:
    bool isMatch(string s, string p)
    {
        int m = s.size(), n = p.size();
        vector<vector<bool>>dp(m + 1, vector<bool>(n + 1));
        dp[0][0] = true;

        for (int i = 1; i <= n; i++)
        {
            int count = 0, len = i;
            if (len & 1) dp[0][i] = false;
            else
            {
                int j = i;
                while (j > 0)
                {
                    if (p[j - 1] == '*') count++;
                    j--;
                }

                dp[0][i] = count == len / 2;
            }
        }

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s[i - 1] == p[j - 1] or p[j - 1] == '.') dp[i][j] = dp[i - 1][j - 1];
                else if (p[j - 1] == '*')
                {
                    dp[i][j] = dp[i][j - 2]; //not matching even a single char, i.e. a* = ""
                    //matching a single char
                    if (s[i - 1] == p[j - 2] or p[j - 2] == '.')   dp[i][j] = dp[i][j] || dp[i - 1][j];
                }
            }
        }

        return dp[m][n];
    }
};

//Bottom Up DP, with space optimisation
//Time complexity - O(m*n)
//Space complexity - O(n)
class Solution {
public:
    bool isMatch(string s, string p)
    {
        int m = s.size(), n = p.size();
        vector<bool>prev(n + 1);
        prev[0] = true;

        for (int i = 1; i <= n; i++)
        {
            int count = 0, len = i;
            if (len & 1) prev[i] = false;
            else
            {
                int j = i;
                while (j > 0)
                {
                    if (p[j - 1] == '*') count++;
                    j--;
                }

                prev[i] = count == len / 2;
            }
        }

        for (int i = 1; i <= m; i++)
        {
            vector<bool>curr(n + 1);
            for (int j = 1; j <= n; j++)
            {
                if (s[i - 1] == p[j - 1] or p[j - 1] == '.') curr[j] = prev[j - 1];
                else if (p[j - 1] == '*')
                {
                    curr[j] = curr[j - 2];
                    if (s[i - 1] == p[j - 2] or p[j - 2] == '.')   curr[j] = curr[j] || prev[j];
                }
            }
            prev = curr;
        }

        return prev[n];
    }
};

//Bottom Up DP
//Time complexity - O(m*n)
//Space complexity - O(m*n)
class Solution {
public:
    bool isMatch(string s, string p)
    {
        int m = p.size(), n = s.size();
        vector<vector<bool>>dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;

        for (int i = 2; i <= m; i++)
        {
            if (p[i - 1] == '*')   dp[i][0] = dp[i - 2][0];
        }

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if ((s[j - 1] == p[i - 1]) or (p[i - 1] == '.'))   dp[i][j] = dp[i - 1][j - 1];
                else if (p[i - 1] == '*')
                {
                    dp[i][j] = dp[i - 2][j];
                    if ((s[j - 1] == p[i - 2]) or (p[i - 2] == '.'))   dp[i][j] = dp[i][j] || dp[i][j - 1];
                }
            }
        }

        return dp[m][n];
    }
};