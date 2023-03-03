//Recursion
//Time complexity - O(2^n)
//Space complexity - O(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        int n = nums.size();

        return lis(0, n, nums);
    }

    int lis(int i, int n, vector<int>&nums, int prev = INT_MIN)
    {
        if (i >= n)    return 0; //no elements


        int exc = lis(i + 1, n, nums, prev);
        int inc = 0;

        if (nums[i] > prev)    inc = 1 + lis(i + 1, n, nums, nums[i]);

        return max(inc, exc);
    }
};

//Top Down DP
//Time complexity - O(n^2)
//Space complexity - O(n^2)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));

        return lisTD(0, n, nums, -1, dp);
    }

    int lisTD(int i, int n, vector<int>&nums, int prev_index, vector<vector<int>>&dp)
    {
        if (i == n)    return 0; //0 elements

        if (prev_index != -1 && dp[i][prev_index] != -1)   return dp[i][prev_index];

        int exc = lisTD(i + 1, n, nums, prev_index, dp);
        int inc = 0;

        if (prev_index == -1 or nums[i] > nums[prev_index])    inc = 1 + lisTD(i + 1, n, nums, i, dp);

        if (prev_index != -1)  dp[i][prev_index] = max(inc, exc);
        return max(inc, exc);
    }
};

//Top Down DP
//Time complexity - O(n^2)
//Space complexity - O(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        vector<int>dp(nums.size(), -1);
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (dp[i] == -1)    helper(i, nums, dp);
        }

        return *max_element(dp.begin(), dp.end());
    }

    int helper(int i, vector<int>&nums, vector<int>&dp)
    {
        if (dp[i] != -1) return dp[i];
        int ans = 1;
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])   ans = max(ans, 1 + helper(j, nums, dp));
        }
        return dp[i] = ans;
    }
};

//Bottom Up DP
//Time complexity - O(n^2)
//Space complexity - O(n)
#define vi vector<int>
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        return lisBU(nums, n);
    }

    int lisBU(vi &v, int n)
    {
        vi dp(n, 1); //dp[i] denotes the length of LIS ending at index i

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (v[j] < v[i])    dp[i] = max(dp[i], 1 + dp[j]);
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};

//Binary Search
//Time complexity - O(n*logn)
//Space complexity - O(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        vector<int>sub;

        for (int num : nums)
        {
            if (sub.size() == 0 or sub[sub.size() - 1] < num)
            {
                sub.push_back(num);
            }

            else
            {
                int index = lower_bound(sub.begin(), sub.end(), num) - sub.begin();
                sub[index] = num;
            }
        }

        return sub.size();
    }
};