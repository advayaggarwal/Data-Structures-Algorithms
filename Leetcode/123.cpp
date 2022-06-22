//Recursion
//Time complexity - O(2^n)
//Space complexity - O(n)
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        return helper(0, 1, prices, 2);    // 1->buy, 0->sell
    }

    int helper(int i, int buyOrSell, vector<int>&prices, int k)
    {
        if (i >= prices.size() or k == 0)  return 0;

        int noTransact = helper(i + 1, buyOrSell, prices, k);
        int transact = 0;

        if (buyOrSell)   transact = -prices[i] + helper(i + 1, 0, prices, k);

        else    transact = prices[i] + helper(i + 1, 1, prices, k - 1);

        return max(noTransact, transact);
    }
};

//Top Down DP
//Time complexity - O(n*2*k)
//Space complexity - O(n)
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        unordered_map<string, int>dp;
        return helper(0, 1, prices, 2, dp);    // 1->buy, 0->sell
    }

    int helper(int i, int buyOrSell, vector<int>&prices, int k, unordered_map<string, int>&dp)
    {
        if (i >= prices.size() or k == 0)  return 0;

        string key = to_string(i) + "Advay" + to_string(buyOrSell) + "Aggarwal" + to_string(k);

        if (dp.find(key) != dp.end())    return dp[key];

        int noTransact = helper(i + 1, buyOrSell, prices, k, dp);
        int transact = 0;

        if (buyOrSell)   transact = -prices[i] + helper(i + 1, 0, prices, k, dp);

        else    transact = prices[i] + helper(i + 1, 1, prices, k - 1, dp);

        return dp[key] = max(noTransact, transact);
    }
};

//Using 3d array
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        int dp[n + 1][2][3];
        memset(dp, -1, sizeof(dp));
        return helper(0, 1, prices, 2, dp);    // 1->buy, 0->sell
    }

    int helper(int i, int buyOrSell, vector<int>&prices, int k, int dp[][2][3])
    {
        if (i >= prices.size() or k == 0)  return 0;


        if (dp[i][buyOrSell][k] != -1)    return dp[i][buyOrSell][k];

        int noTransact = helper(i + 1, buyOrSell, prices, k, dp);
        int transact = 0;

        if (buyOrSell)   transact = -prices[i] + helper(i + 1, 0, prices, k, dp);

        else    transact = prices[i] + helper(i + 1, 1, prices, k - 1, dp);

        return dp[i][buyOrSell][k] = max(noTransact, transact);
    }
};

//Using 3d vector
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return helper(0, prices, 1, 2, dp);
    }

    int helper(int i, vector<int>&prices, int buy, int k, vector<vector<vector<int>>>&dp)
    {
        if (i == prices.size() or k == 0)  return 0;
        if (dp[i][buy][k] != -1) return dp[i][buy][k];

        if (buy) return dp[i][buy][k] = max(-prices[i] + helper(i + 1, prices, 0, k, dp), helper(i + 1, prices, 1, k, dp));

        else    return dp[i][buy][k] = max(prices[i] + helper(i + 1, prices, 1, k - 1, dp), helper(i + 1, prices, 0, k, dp));
    }
};

//Bottom Up DP
//Time complexity - O(n*2*(k+1))
//Space complexity - O(n*2*3)
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n + 1, vector<vector<int>>(2, vector<int>(3)));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int k = 1; k <= 2; k++)
                {
                    if (buy) dp[i][buy][k] = max(-prices[i] + dp[i + 1][0][k], dp[i + 1][1][k]);
                    else    dp[i][buy][k] = max(prices[i] + dp[i + 1][1][k - 1], dp[i + 1][0][k]);
                }
            }
        }

        return dp[0][1][2];
    }
};

//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int min_price1 = INT_MAX, min_price2 = INT_MAX;
        int profit1 = 0, profit2 = 0;
        int n = prices.size();

        for (int i = 0; i < n; i++)
        {
            min_price1 = min(min_price1, prices[i]);
            profit1 = max(profit1, prices[i] - min_price1);

            min_price2 = min(min_price2, prices[i] - profit1);
            profit2 = max(profit2, prices[i] - min_price2);
        }

        return profit2;
    }
};