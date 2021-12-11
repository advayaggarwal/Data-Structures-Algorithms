//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/discuss/1521820/C%2B%2B-or-Four-Solutions-%3A-Recursion-Memoization-DP-with-O(N)-space-DP-with-O(1)-Space

//Recursion
//Time complexity - O(2^n)
//Space complexity - O(n)
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();

        // 1 -> buy, 0 -> sell
        return helper(0, n, 1, prices); //first we should buy then only we can sell
    }

    int helper(int i, int n, int buy, vector<int>&prices)
    {
        if (i >= n)  return 0;

        int x = 0;

        if (buy)
        {
            int ifBuy = helper(i + 1, n, 0, prices) - prices[i];//we have bought so in future we should first sell it
            int noBuy = helper(i + 1, n, 1, prices);
            x = max(ifBuy, noBuy);
        }

        else
        {
            int ifSell = prices[i] + helper(i + 2, n, 1, prices);//we have sold so in future we should first buy it
            int noSell = helper(i + 1, n, 0, prices);
            x = max(ifSell, noSell);
        }

        return x;
    }
};

//Top Down DP
//Time complexity - O(2*n), we have 2*n states
//Space complexity - O(2*n)
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        vector<vector<int>>dp(n + 1, vector<int>(2, -1));
        return helper(0, n, 1, prices, dp); // 1 -> buy, 0 -> sell
    }

    int helper(int i, int n, int buy, vector<int>&prices, vector<vector<int>>&dp)
    {
        if (i >= n)  return 0;

        if (dp[i][buy] != -1)    return dp[i][buy];

        int x = 0;

        if (buy)
        {
            int ifBuy = helper(i + 1, n, 0, prices, dp) - prices[i];
            int noBuy = helper(i + 1, n, 1, prices, dp);
            x = max(ifBuy, noBuy);
        }

        else
        {
            int ifSell = prices[i] + helper(i + 2, n, 1, prices, dp);
            int noSell = helper(i + 1, n, 0, prices, dp);
            x = max(ifSell, noSell);
        }

        return dp[i][buy] = x;
    }
};