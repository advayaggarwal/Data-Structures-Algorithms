//Top Down DP
//Time complexity - O(n^2)
//Space complexity - O(n)
class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size() + 1, -1);
        return helper(nums, 0, dp);
    }

    int helper(vector<int>&nums, int index, vector<int>&dp)
    {
        if (index == nums.size() - 1)    return 0;
        if (index >= nums.size())    return INT_MAX;
        if (dp[index] != -1)   return dp[index];
        int ans = INT_MAX;

        for (int jump = 1; jump <= nums[index]; jump++)
        {
            int subprob = helper(nums, index + jump, dp);

            if (subprob != INT_MAX) ans = min(ans, 1 + helper(nums, index + jump, dp));
        }
        return dp[index] = ans;
    }
};

//Bottom Up DP
//Time complexity - O(n^2)
//Space complexity - O(n)
class Solution {
public:
    int jump(vector<int>& nums) {

        int n = nums.size();
        vector<int>dp(n, 0);

        for (int i = n - 2; i >= 0; i--)
        {
            int ans = INT_MAX;

            for (int jumps = 1; jumps <= nums[i] && i + jumps < n; jumps++)
            {
                if (dp[i + jumps] != INT_MAX)    ans = min(ans, 1 + dp[i + jumps]);
            }

            dp[i] = ans;
        }
        return dp[0];
    }
};

//Greedy
//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    int jump(vector<int>& nums)
    {
        int currentReach = 0, maxReach = 0;
        int n = nums.size();
        int jumps = 0;

        for (int i = 0; i < n - 1; i++)
        {
            maxReach = max(maxReach, i + nums[i]);

            if (i == currentReach)
            {
                jumps++;
                currentReach = maxReach;
            }
        }

        return jumps;
    }
};