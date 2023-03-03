/*
....i....j...
<---n------->

n = k+j-i+1, where k is number of multiplications done till now
j = n-1-(k-i)
*/

//Top Down DP
//Time complexity - O(m^2)
//Space complexity - O(m*m)
class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers)
    {
        int m = multipliers.size();
        vector<vector<int>>dp(m, vector<int>(m, INT_MIN));
        return helper(0, nums, 0, multipliers, dp);
    }

    int helper(int i, vector<int>&nums, int k, vector<int>&multipliers, vector<vector<int>>&dp)
    {
        if (k == multipliers.size()) return 0;
        if (dp[i][k] != INT_MIN)   return dp[i][k];
        int n = nums.size();
        int front = nums[i] * multipliers[k] + helper(i + 1, nums, k + 1, multipliers, dp);
        int back = nums[n - 1 - (k - i)] * multipliers[k] + helper(i, nums, k + 1, multipliers, dp);
        return dp[i][k] = max(front, back);
    }
};


//Bottom Up DP
//Time complexity - O(m^2)
//Space complexity - O(m^2)
class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers)
    {
        int n = nums.size(), m = multipliers.size();
        vector<vector<int>>dp(m + 1, vector<int>(m + 1));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int k = m - 1; k >= 0 && k >= i; k--)
            {
                long long front = nums[i] * 1LL * multipliers[k] + dp[i + 1][k + 1];
                long long back = nums[n - 1 - (k - i)] * 1LL * multipliers[k] + dp[i][k + 1];
                dp[i][k] = max(front, back);
            }
        }

        return dp[0][0];
    }
};

//Bottom Up DP with space optimisation
//Time complexity - O(m^2)
//Space complexity - O(m)
class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers)
    {
        int n = nums.size(), m = multipliers.size();
        vector<int>curr(m + 1), next(m + 1);

        for (int i = n - 1; i >= 0; i--)
        {
            for (int k = m - 1; k >= 0 && k >= i; k--)
            {
                long long front = nums[i] * 1LL * multipliers[k] + next[k + 1];
                long long back = nums[n - 1 - (k - i)] * 1LL * multipliers[k] + curr[k + 1];
                curr[k] = max(front, back);
            }

            next = curr;
        }

        return curr[0];
    }
};