//Recursion
//Time complexity - O(n^target)
//Space complexity - O(target)
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target)
    {
        return helper(nums, target);
    }

    int helper(vector<int>&nums, int target)
    {
        if (target == 0) return 1;
        int ans = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[j] <= target)
            {
                ans += helper(nums, target - nums[j]);
            }
        }

        return ans;
    }
};

//Top Down DP
//Time complexity - O(n*target)
//Space complexity - O(target)
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target)
    {
        vector<int>dp(target + 1, -1);
        return helper(nums, target, dp);
    }

    int helper(vector<int>&nums, int target, vector<int>&dp)
    {
        if (target == 0) return 1;
        if (dp[target] != -1)  return dp[target];

        int ans = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[j] <= target)
            {
                ans += helper(nums, target - nums[j], dp);
            }
        }

        return dp[target] = ans;
    }
};

//Bottom Up DP
//Time complexity - O(n*target)
//Space complexity - O(target)
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target)
    {
        vector<int>dp(target + 1);
        int n = nums.size();
        dp[0] = 1;

        for (int i = 1; i <= target; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (nums[j] <= i && long(dp[i]) + dp[i - nums[j]] <= INT_MAX)  dp[i] += dp[i - nums[j]]; //To avoid overflow
            }
        }

        return dp[target];
    }
};