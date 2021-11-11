//Top Down DP
//Time complexity - O(n)
//Space complexity - O(n)
#define vi vector<int>
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vi dp(n, -1);

        return maxNonAdjacentSumTD(nums, 0, n, dp);
    }

    int maxNonAdjacentSumTD(vi &v, int index, int n, vi &dp)
    {
        if (index == n - 1) return v[index];
        if (index >= n) return 0;

        if (dp[index] != -1)    return dp[index];

        int inc = v[index] + maxNonAdjacentSumTD(v, index + 2, n, dp);
        int exc = maxNonAdjacentSumTD(v, index + 1, n, dp);

        return dp[index] = max(inc, exc);
    }
};

//Bottom Up DP
//Time complexity - O(n)
//Space complexity - O(n)
#define vi vector<int>
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        return maxNonAdjacentSumBU(nums, n);
    }

    int maxNonAdjacentSumBU(vi &v, int n)
    {
        vi dp(n, 0); //dp[i] denotes the maximum non adjacent sum you can get from 1st i+1 elements

        dp[0] = v[0];
        if (n > 1)  dp[1] = max(v[0], v[1]);

        for (int i = 2; i < n; i++)
        {
            int inc = v[i] + dp[i - 2];
            int exc = dp[i - 1];

            dp[i] = max(inc, exc);
        }

        return dp[n - 1];
    }
};