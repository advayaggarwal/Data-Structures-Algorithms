//Recursion
//Time complexity - Exponential
class Solution {
public:
    int minOperations(vector<int>& nums, int x)
    {
        int n = nums.size();
        int ans = helper(0, n - 1, nums, x);
        return ans >= 1e9 ? -1 : ans;
    }

    int helper(int i, int j, vector<int>&nums, int x)
    {
        if (x == 0)  return 0;
        if (i > j or x < 0)   return 1e9;

        return 1 + min(helper(i + 1, j, nums, x - nums[i]), helper(i, j - 1, nums, x - nums[j]));
    }
};

//Top Down DP
//Time complexity - O(x*(n^2))
class Solution {
public:
    int minOperations(vector<int>& nums, int x)
    {
        int n = nums.size();
        unordered_map<string, int>dp;
        int ans = helper(0, n - 1, nums, x, dp);
        return ans >= 1e9 ? -1 : ans;
    }

    int helper(int i, int j, vector<int>&nums, int x, unordered_map<string, int>&dp)
    {
        if (x == 0)  return 0;
        if (i > j or x < 0)   return 1e9;

        string key = to_string(i) + "#" + to_string(j) + "#" + to_string(x);
        if (dp.count(key))   return dp[key];

        return dp[key] = 1 + min(helper(i + 1, j, nums, x - nums[i], dp), helper(i, j - 1, nums, x - nums[j], dp));
    }
};

//Binary Search on prefix and suffix sum
//Time complexity - O(nlogn)
//Space complexity - O(n)
class Solution {
public:
    int minOperations(vector<int>& nums, int x)
    {
        int n = nums.size();

        vector<int>prefix(n), suffix(n);
        prefix[0] = nums[0];
        suffix[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] + nums[i];
            suffix[n - i - 1] = suffix[n - i] + nums[n - i - 1];
        }

        int ans = INT_MAX;

        for (int i = n - 1; i >= 0; i--)
        {
            int target = x - suffix[i];

            if (target == 0) ans = min(ans, n - i);
            else if (target > 0)
            {
                int idx = lower_bound(prefix.begin(), prefix.end(), target) - prefix.begin();
                if ((idx != n) && (i > idx) && prefix[idx] == target) ans = min(ans, n - i + idx + 1);
            }
        }

        int idx = lower_bound(prefix.begin(), prefix.end(), x) - prefix.begin();
        if ((idx != n) && prefix[idx] == x) ans = min(ans, idx + 1);

        return ans == INT_MAX ? -1 : ans;
    }
};

//Same as above, just used unordered map to store prefix sums along with index
//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    int minOperations(vector<int>& nums, int x)
    {
        int n = nums.size();
        unordered_map<int, int>prefix;
        prefix[nums[0]] = 0;
        int sum = nums[0];
        for (int i = 1; i < n; i++)
        {
            sum += nums[i];
            prefix[sum] = i;
        }

        int ans = prefix.count(x) > 0 ? prefix[x] + 1 : INT_MAX;
        sum = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            sum += nums[i];
            int target = x - sum;

            if (target == 0) ans = min(ans, n - i);
            else if (target > 0)
            {
                if (prefix.count(target) && (i > prefix[target]))    ans = min(ans, n - i + prefix[target] + 1);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};

/*
    Sliding Window
    Find the maximum subarray having sum = totalSum-x
    So that will minimise our actual answer
*/
//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    int minOperations(vector<int>& nums, int x)
    {
        int n = nums.size(), sum = 0;
        for (int i = 0; i < n; i++) sum += nums[i];
        int target = sum - x, i = 0, j = 0;

        int ans = INT_MIN;
        sum = 0;
        while (j < n)
        {
            sum += nums[j];
            while (i <= j && sum > target)    sum -= nums[i++];
            if (sum == target)   ans = max(ans, j - i + 1);
            j++;
        }

        return ans == INT_MIN ? -1 : n - ans;
    }
};