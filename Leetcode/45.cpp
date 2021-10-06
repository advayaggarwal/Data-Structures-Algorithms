//Top Down DP
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

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, -1);
        dp[n - 1] = 0;

        for (int i = n - 2; i >= 0; i--)
        {
            if (i + nums[i] >= n - 1)   dp[i] = 1;

            else
            {
                int minj = INT_MAX;
                bool flag = false;
                for (int j = i + 1; j <= (i + nums[i]); j++)
                {
                    flag = true;
                    if (dp[j] == 1)
                    {
                        dp[i] = 2;
                        break;
                    }
                    minj = min(minj, dp[j]);
                }

                if (dp[i] == -1)
                {
                    if (!flag || minj == INT_MAX ) dp[i] = INT_MAX;
                    else dp[i] =  1 + minj;
                }
            }
        }

        return dp[0];
    }
};