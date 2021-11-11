//Top Down DP
//Time complexity - O(n*amount)
//Space complexity - O(n*amount)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>>dp(n + 1, vector<int>(amount + 1, -1));
        int ans = helper(0, n, coins, amount, dp);

        return ans == INT_MAX - 1 ? -1 : ans;
    }

    int helper(int i, int n, vector<int>&coins, int amount, vector<vector<int>>&dp)
    {
        if (amount == 0)  return 0;

        if (i >= n)    return INT_MAX - 1;

        if (dp[i][amount] != -1)   return dp[i][amount];

        int inc = INT_MAX - 1;

        if (coins[i] <= amount)  inc = 1 + helper(i, n, coins, amount - coins[i], dp);

        int exc = helper(i + 1, n, coins, amount, dp);

        return dp[i][amount] = min(inc, exc);
    }
};


//Bottom Up DP
//Time complexity - O(n*amount)
//Space complexity - O(n*amount)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>>dp(n + 1, vector<int>(amount + 1, 0));

        for (int i = 1; i <= amount; i++)    dp[0][i] = INT_MAX - 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= amount; j++)
            {
                if (coins[i - 1] <= j) dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coins[i - 1]]);
                else dp[i][j] = dp[i - 1][j];
            }
        }

        return dp[n][amount] == INT_MAX - 1 ? -1 : dp[n][amount];
    }
};

//Time complexity - O(n*amount)
//Space complexity - O(amount)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount + 1, amount + 1);

        dp[0] = 0;

        for (int i = 1; i <= amount; i++)
        {
            for (int j = 0; j < coins.size(); j++)
            {
                if (coins[j] <= i)
                {
                    dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
                }
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];
    }
};