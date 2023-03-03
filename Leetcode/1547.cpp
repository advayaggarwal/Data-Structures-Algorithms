//Time complexity - O(c^3), where c is cuts.size()
//Space complexity - O(c^2)
class Solution {
public:
    int minCost(int n, vector<int>& cuts)
    {
        cuts.push_back(n);
        cuts.push_back(0);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>>dp(cuts.size(), vector<int>(cuts.size(), -1));
        return helper(1, cuts.size() - 2, cuts, dp);
    }

    int helper(int i, int j, vector<int>&cuts, vector<vector<int>>&dp)
    {
        if (i > j)  return 0;
        if (dp[i][j] != -1)  return dp[i][j];

        int ans = INT_MAX;
        for (int k = i; k <= j; k++)
        {
            ans = min(ans, helper(i, k - 1, cuts, dp) + helper(k + 1, j, cuts, dp) + cuts[j + 1] - cuts[i - 1]);
        }

        return dp[i][j] = ans;
    }
};