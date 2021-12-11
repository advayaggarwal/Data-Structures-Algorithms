//Recursion
//Time complexity - O(n*(n^n))
//Space complexity - O(n)
class Solution {
public:
    int integerBreak(int n)
    {
        if (n <= 2)    return 1;

        int ans = INT_MIN;

        for (int i = 1; i < n; i++)
        {
            ans = max({ans, i * integerBreak(n - i), i * (n - i)});
        }

        return ans;
    }
};


//Top Down DP
//Time complexity - O(n^2)
//Space complexity - O(n)
class Solution {
public:
    int integerBreak(int n)
    {
        vector<int>dp(n + 1, -1);

        return helper(n, dp);
    }

    int helper(int n, vector<int>&dp)
    {
        if (n <= 2)    return 1;

        if (dp[n] != -1)   return dp[n];
        int ans = INT_MIN;

        for (int i = 1; i < n; i++)
        {
            ans = max({ans, i * helper(n - i, dp), i * (n - i)});
        }

        return dp[n] = ans;
    }
};


//Bottom Up DP
//Time complexity - O(n^2)
//Space complexity - O(n)
class Solution {
public:
    int integerBreak(int n)
    {
        vector<int>dp(n + 1, INT_MIN);
        dp[0] = dp[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            for (int sum = 1; sum < i; sum++)
            {
                dp[i] = max({dp[i], sum * dp[i - sum], sum * (i - sum)});
            }
        }

        return dp[n];
    }
};


//Math
//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    int integerBreak(int n)
    {
        if (n == 2)    return 1;
        if (n == 3)    return 2;

        int prod = 1;

        while (n > 4)
        {
            prod *= 3;
            n -= 3;
        }

        prod *= n;
        return prod;
    }
};