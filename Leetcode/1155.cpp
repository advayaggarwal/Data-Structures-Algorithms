//Recursion
//Time complexity - O(2^(n*target)*k)
//Space complexity - O(n)
class Solution {
public:
    int mod = 1e9 + 7;
    int numRollsToTarget(int n, int k, int target)
    {
        return helper(0, n, k, target);
    }

    int helper(int i, int n, int k, int target)
    {
        if (i == n)  return target == 0;

        int ans = 0;
        for (int f = 1; f <= k; f++)
        {
            if (target >= f)    ans = (ans + helper(i + 1, n, k, target - f)) % mod;
            else break;
        }

        return ans;
    }
};

//Top Down DP
//Time complexity - O(n*target*k)
//Space complexity - O(n*target)
class Solution {
public:
    int mod = 1e9 + 7;
    int numRollsToTarget(int n, int k, int target)
    {
        vector<vector<int>>dp(n, vector<int>(target + 1, -1));
        return helper(0, n, k, target, dp);
    }

    int helper(int i, int n, int k, int target, vector<vector<int>>&dp)
    {
        if (i == n)  return target == 0;
        if (dp[i][target] != -1) return dp[i][target];

        int ans = 0;
        for (int f = 1; f <= k; f++)
        {
            if (target >= f)    ans = (ans + helper(i + 1, n, k, target - f, dp)) % mod;
            else break;
        }

        return dp[i][target] = ans;
    }
};

//Bottom Up DP
//Time complexity - O(n*target*k)
//Space complexity - O(n*target)
class Solution {
public:
    int mod = 1e9 + 7;
    int numRollsToTarget(int n, int k, int target)
    {
        vector<vector<int>>dp(n + 1, vector<int>(target + 1));
        dp[n][0] = 1;

        for (int i = n - 1; i >= 0; i--)
        {
            for (int t = target; t >= 0; t--)
            {
                int ans = 0;
                for (int f = 1; f <= k; f++)
                {
                    if (t >= f)  ans = (ans + dp[i + 1][t - f]) % mod;
                    else break;
                }

                dp[i][t] = ans;
            }
        }

        return dp[0][target];
    }
};

//Bottom Up DP with space optimisation
//Time complexity - O(n*target*k)
//Space complexity - O(target)
class Solution {
public:
    int mod = 1e9 + 7;
    int numRollsToTarget(int n, int k, int target)
    {
        vector<int>curr(target + 1), next(target + 1);
        next[0] = 1;

        for (int i = n - 1; i >= 0; i--)
        {
            for (int t = target; t >= 0; t--)
            {
                int ans = 0;
                for (int f = 1; f <= k; f++)
                {
                    if (t >= f)  ans = (ans + next[t - f]) % mod;
                    else break;
                }

                curr[t] = ans;
            }

            next = curr;
        }

        return curr[target];
    }
};