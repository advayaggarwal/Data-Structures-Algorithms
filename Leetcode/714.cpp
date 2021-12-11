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