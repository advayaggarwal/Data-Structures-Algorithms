//Recursion
//Time complexity - O(2^n)
//Space complexity - O(n)
class Solution {
public:
    int maxProfit(int k, vector<int>& prices)
    {
        return helper(0, 1, prices, k);    // 1->buy, 0->sell
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
    int maxProfit(int k, vector<int>& prices)
    {
        /* Optimisation, it means we can do every transaction which gives us profit -> Greedy
        if(k > prices.size()/2)
        {
            int ans = 0;
            int n = prices.size();
            for(int i=0; i<n-1; i++)
            {
                if(prices[i] < prices[i+1]) ans += prices[i+1]-prices[i];
            }

            return ans;
        }
        */
        unordered_map<string, int>dp;
        return helper(0, 1, prices, k, dp);    // 1->buy, 0->sell
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
    int maxProfit(int k, vector<int>& prices)
    {
        int n = prices.size();
        int dp[n + 1][2][101];
        memset(dp, -1, sizeof(dp));
        return helper(0, 1, prices, k, dp);    // 1->buy, 0->sell
    }

    int helper(int i, int buyOrSell, vector<int>&prices, int k, int dp[][2][101])
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