//Time complexity - O(m*target*n^2)
//Space complexity - O(m*n*target)
class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target)
    {
        vector<vector<vector<int>>>dp(m, vector<vector<int>>(n + 1, vector<int>(target + 1, -1)));
        int ans = helper(0, 0, 0, houses, cost, target, dp);
        return ans >= 1e7 ? -1 : ans;
    }

    int helper(int i, int prevColor, int k, vector<int>&houses, vector<vector<int>>&cost, int target, vector<vector<vector<int>>>&dp)
    {
        if (k > target)  return 1e7;
        if (i == houses.size())
        {
            if (k == target) return 0;
            return 1e7;
        }

        if (dp[i][prevColor][k] != -1)   return dp[i][prevColor][k];

        if (houses[i] != 0)
        {
            if (prevColor == houses[i])    return dp[i][prevColor][k] = helper(i + 1, prevColor, k, houses, cost, target, dp);
            return dp[i][prevColor][k] = helper(i + 1, houses[i], k + 1, houses, cost, target, dp);
        }

        int ans = 1e7;
        for (int col = 0; col < cost[0].size(); col++)
        {
            if (prevColor != col + 1)
            {
                ans = min(ans, cost[i][col] + helper(i + 1, col + 1, k + 1, houses, cost, target, dp));
            }

            else
            {
                ans = min(ans, cost[i][col] + helper(i + 1, col + 1, k, houses, cost, target, dp));
            }
        }

        return dp[i][prevColor][k] = ans;
    }
};