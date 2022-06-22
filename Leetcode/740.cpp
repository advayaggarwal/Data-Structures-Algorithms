//Transforming this question into house robber(Max sum non adjacent elements)

//Bottom Up DP
//Time complexity - O(n+mx)
//Space complexity - O(mx)
class Solution {
public:
    int deleteAndEarn(vector<int>& nums)
    {
        int n = nums.size();
        int mx = INT_MIN;

        for (int i = 0; i < n; i++)  mx = max(mx, nums[i]);
        vector<int>freq(mx + 1);

        for (int i = 0; i < n; i++)  freq[nums[i]]++;
        vector<int>dp(mx + 1, -1);
        return helper(mx, freq, dp);
    }

    int helper(int i, vector<int>&freq, vector<int>&dp)
    {
        if (i == 0)    return 0;
        if (i == 1)    return freq[1];
        if (dp[i] != -1)   return dp[i];

        int take = freq[i] * i + helper(i - 2, freq, dp);
        int notTake = helper(i - 1, freq, dp);

        return dp[i] = max(take, notTake);
    }
};

//Top Down DP
//Time complexity - O(n+mx)
//Space complexity - O(mx)
class Solution {
public:
    int deleteAndEarn(vector<int>& nums)
    {
        int n = nums.size();
        int mx = INT_MIN;

        for (int i = 0; i < n; i++)  mx = max(mx, nums[i]);
        vector<int>freq(mx + 1);

        for (int i = 0; i < n; i++)  freq[nums[i]]++;
        vector<int>dp(mx + 1, -1);

        dp[0] = 0;
        dp[1] = freq[1];

        for (int i = 2; i <= mx; i++)
        {
            dp[i] = max(i * freq[i] + dp[i - 2], dp[i - 1]);
        }

        return dp[mx];
    }
};

//Top Down DP without dp vector
//Time complexity - O(n+mx)
//Space complexity - O(mx)
class Solution {
public:
    int deleteAndEarn(vector<int>& nums)
    {
        int n = nums.size();
        int mx = INT_MIN;

        for (int i = 0; i < n; i++)  mx = max(mx, nums[i]);
        vector<int>freq(mx + 1);

        for (int i = 0; i < n; i++)  freq[nums[i]]++;

        int prev1 = freq[1], prev2 = 0;

        for (int i = 2; i <= mx; i++)
        {
            int curr = max(i * freq[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};