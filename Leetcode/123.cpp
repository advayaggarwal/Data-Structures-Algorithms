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