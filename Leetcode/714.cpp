//Top Down DP
//Time complexity - O(2*n)
//Space complexity - O(n)
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee)
    {
        int n = prices.size();
        vector<vector<int>>dp(n + 1, vector<int>(2, -1));
        return helper(0, n, 1, prices, dp, fee);
    }

    int helper(int i, int n, int buy, vector<int>&prices, vector<vector<int>>&dp, int fee)
    {
        if (i >= n)  return 0;
        if (dp[i][buy] != -1)    return dp[i][buy];

        int noTransact = helper(i + 1, n, buy, prices, dp, fee);
        int transact = 0;

        if (buy)    transact = helper(i + 1, n, 0, prices, dp, fee) - prices[i] - fee;

        else    transact = prices[i] + helper(i + 1, n, 1, prices, dp, fee);

        return dp[i][buy] = max(transact, noTransact);
    }
};

//Bottom Up DP
//Time complexity - O(2*n)
//Space complexity - O(2*n)
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee)
    {
        int n = prices.size();
        vector<vector<int>>dp(n + 1, vector<int>(2));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                if (buy) dp[i][buy] = max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);
                else dp[i][buy] = max(prices[i] - fee + dp[i + 1][1], dp[i + 1][0]);
            }
        }

        return dp[0][1];
    }
};

//Bottom Up DP with space optimisation
//Time complexity - O(2*n)
//Space complexity - O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee)
    {
        int n = prices.size();
        vector<int>curr(2), after(2);

        for (int i = n - 1; i >= 0; i--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                if (buy) curr[buy] = max(-prices[i] + after[0], after[1]);
                else curr[buy] = max(prices[i] - fee + after[1], after[0]);

                after = curr;
            }
        }

        return after[1];
    }
};