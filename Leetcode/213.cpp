/*
Since House[1] and House[n] are adjacent, they cannot be robbed together. Therefore, the problem becomes to rob
either House[1]-House[n-1] or House[2]-House[n], depending on which choice offers more money. Now the problem
has degenerated to the House Robber, which is already been solved.
*/
//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    int rob(vector<int>& nums)
    {
        int n = nums.size();
        if (n == 1)    return nums[0];
        vector<int>dp(n, -1);

        int op1 = robHouse(0, n - 1, nums, dp); //rob houses from 0 to n-2
        dp = vector<int>(n, -1);
        int op2 = robHouse(1, n, nums, dp); //rob houses from 1 to n-1
        return max(op1, op2);
    }

    int robHouse(int i, int n, vector<int>&nums, vector<int>&dp)
    {
        if (i >= n)    return 0;
        if (dp[i] != -1)   return dp[i];

        return dp[i] = max(nums[i] + robHouse(i + 2, n, nums, dp), robHouse(i + 1, n, nums, dp));
    }
};