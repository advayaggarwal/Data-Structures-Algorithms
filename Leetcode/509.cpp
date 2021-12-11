//Recursion
//Time complexity - O(2^n)
//Space complexity - O(n)
class Solution {
public:
    int fib(int n)
    {
        if (n < 2)   return n;

        return fib(n - 1) + fib(n - 2);
    }
};

//Top Down DP
//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    int fib(int n)
    {
        vector<int>dp(n + 1, -1);
        return helper(n, dp);
    }

    int helper(int n, vector<int>&dp)
    {
        if (n < 2)   return n;

        if (dp[n] != -1) return dp[n];

        return dp[n] = helper(n - 1, dp) + helper(n - 2, dp);
    }
};

//Bottom Up DP
//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    int fib(int n)
    {
        if (n == 0)    return 0;
        vector<int>dp(n + 1);
        dp[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};

//Bottom Up DP
//Time complexity - O(n)
//Space complexity - O(1), only need two previous states
class Solution {
public:
    int fib(int n)
    {
        if (n == 0)    return 0;

        int prev = 0, cur = 1;

        for (int i = 2; i <= n; i++)
        {
            int temp = prev + cur;
            prev = cur;
            cur = temp;
        }

        return cur;
    }
};