//Time complexity - O(n*2)
//Space complexity - O(n)
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        vector<vector<int>>dp(prices.size(), vector<int>(2, -1));
        return helper(0, prices, 1, dp);
    }
    //buy = 1, I can buy
    //buy = 0, I can't buy
    int helper(int i, vector<int>&prices, int buy, vector<vector<int>>&dp)
    {
        if (i == prices.size())  return 0;
        if (dp[i][buy] != -1)    return dp[i][buy];
        int ans = 0;

        if (buy) ans = -prices[i] + helper(i + 1, prices, 0, dp);
        else ans = prices[i] + helper(i + 1, prices, 1, dp);

        return dp[i][buy] = max(ans, helper(i + 1, prices, buy, dp));
    }
};

//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        int ans = 0;

        for (int i = 0; i < n - 1; i++)
        {
            if (prices[i] < prices[i + 1])
            {
                ans += (prices[i + 1] - prices[i]);
            }
        }

        return ans;
    }
};