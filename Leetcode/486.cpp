//Recursion
//Time complexity - O(n^2)
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {

        int n = nums.size();
        int total = 0;
        for (int i = 0; i < n; i++)  total += nums[i];

        vector<vector<int>>dp(n + 1, vector<int>(n + 1, -1));

        int score = helper(0, n - 1, nums, dp);

        return score >= total - score;
    }

    int helper(int i, int n, vector<int>&nums, vector<vector<int>>&dp)
    {
        if (i > n)   return 0;
        if (i == n)  return nums[i];

        if (dp[i][n] != -1)    return dp[i][n];

        int l = nums[i] + min(helper(i + 2, n, nums, dp), helper(i + 1, n - 1, nums, dp));
        int r = nums[n] + min(helper(i, n - 2, nums, dp), helper(i + 1, n - 1, nums, dp));

        return dp[i][n] = max(l, r);
    }

};