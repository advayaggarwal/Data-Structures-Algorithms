//Recursion
//Time complexity - O(2^n)
//Space complexity - O(n)
class Solution {
public:
    int change(int amount, vector<int>& coins)
    {
        return helper(0, amount, coins);
    }

    int helper(int i, int amount, vector<int>&coins)
    {
        if (i >= coins.size())
        {
            if (amount == 0) return 1;
            return 0;
        }

        int op1 = 0, op2 = 0;
        if (coins[i] <= amount)
        {
            op1 = helper(i, amount - coins[i], coins);
        }

        op2 = helper(i + 1, amount, coins);

        return op1 + op2;
    }
};

//Top Down Dp
//Time complexity - O(n*amount)
//Space complexity - O(n*amount)
class Solution {
public:
    int change(int amount, vector<int>& coins)
    {
        int n = coins.size();
        vector<vector<int>>dp(n + 1, vector<int>(amount + 1, -1));
        return helper(0, amount, coins, dp);
    }

    int helper(int i, int amount, vector<int>&coins, vector<vector<int>>&dp)
    {
        if (i >= coins.size())
        {
            if (amount == 0) return 1;
            return 0;
        }

        if (dp[i][amount] != -1) return dp[i][amount];

        int op1 = 0, op2 = 0;
        if (coins[i] <= amount)
        {
            op1 = helper(i, amount - coins[i], coins, dp);
        }

        op2 = helper(i + 1, amount, coins, dp);

        return dp[i][amount] = op1 + op2;
    }
};

//Bottom Up DP
//Time complexity - O(n*amount)
//Space complexity - O(n*amount)
class Solution {
public:
    int change(int amount, vector<int>& coins)
    {
        int n = coins.size();
        vector<vector<int>>dp(n + 1, vector<int>(amount + 1, 0));
        //dp[i][j] denotes the number of ways to get sum 'j' using 'first i' coins

        for (int i = 0; i <= amount; i++)    dp[0][amount] = 0;
        for (int i = 0; i <= n; i++)    dp[i][0] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= amount; j++)
            {
                int op1 = 0, op2 = 0;
                if (coins[i - 1] <= j) op1 = dp[i][j - coins[i - 1]];
                op2 = dp[i - 1][j];
                dp[i][j] = op1 + op2;
            }
        }

        return dp[n][amount];
    }
};