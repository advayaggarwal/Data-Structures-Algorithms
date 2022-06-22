//Recursion
//Time complexity - O(2^(m*n))
//Space complexity - O(m+n)
class Solution {
public:
    int numDistinct(string s, string t)
    {
        int n = s.size(), m = t.size();
        return helper(n - 1, m - 1, s, t);
    }

    int helper(int i, int j, string &s, string &t)
    {
        if (j < 0)  return 1;
        if (i < 0)  return 0;

        int ans = helper(i - 1, j, s, t); //not match case
        if (s[i] == t[j])    ans += helper(i - 1, j - 1, s, t); //match case

        return ans;
    }
};

//Top Down DP
//Time complexity - O(m*n)
//Space complexity - O(m*n)
class Solution {
public:
    int numDistinct(string s, string t)
    {
        int n = s.size(), m = t.size();
        vector<vector<int>>dp(n, vector<int>(m, -1));
        return helper(n - 1, m - 1, s, t, dp);
    }

    int helper(int i, int j, string &s, string &t, vector<vector<int>>&dp)
    {
        if (j < 0)  return 1;
        if (i < 0)  return 0;

        if (dp[i][j] != -1)   return dp[i][j];

        int ans = helper(i - 1, j, s, t, dp); //not match case
        if (s[i] == t[j])    ans += helper(i - 1, j - 1, s, t, dp); //match case

        return dp[i][j] = ans;
    }
};

//Bottom Up DP
//Time complexity - O(m*n)
//Space complexity - O(m*n)
class Solution {
public:
    int numDistinct(string s, string t)
    {
        int n = s.size(), m = t.size();
        vector<vector<double>>dp(n + 1, vector<double>(m + 1)); //was giving integer overflow, i.e. used double

        for (int i = 0; i <= n; i++) dp[i][0] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if (s[i - 1] == t[j - 1])    dp[i][j] += dp[i - 1][j - 1];
            }
        }

        return (int)dp[n][m];
    }
};

//Bottom Up DP
//Time complexity - O(m*n)
//Space complexity - O(2*m), using 2 arrays
class Solution {
public:
    int numDistinct(string s, string t)
    {
        int n = s.size(), m = t.size();
        vector<double>prev(m + 1), curr(m + 1);
        prev[0] = curr[0] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                curr[j] = prev[j];
                if (s[i - 1] == t[j - 1])    curr[j] += prev[j - 1];
            }

            prev = curr;
        }

        return (int)prev[m];
    }
};

//Bottom Up DP
//Time complexity - O(m*n)
//Space complexity - O(m), using 1 array
class Solution {
public:
    int numDistinct(string s, string t)
    {
        int n = s.size(), m = t.size();
        vector<double>dp(m + 1);
        dp[0] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = m; j >= 1; j--)
            {
                if (s[i - 1] == t[j - 1])    dp[j] += dp[j - 1];
            }
        }

        return (int)dp[m];
    }
};