//Top Down DP
//Time complexity - O(n*k)
//Space complexity - O(n)
class Solution {
public:
    int maxResult(vector<int>& nums, int k)
    {
        vector<int>dp(nums.size(), -1);
        return helper(0, nums.size(), nums, k, dp);
    }

    int helper(int i, int n, vector<int>&nums, int k, vector<int>&dp)
    {
        if (i == n)    return 0;
        if (dp[i] != -1) return dp[i];

        int ans = INT_MIN;
        for (int j = i + 1; j <= min(n - 1, i + k); j++)
        {
            ans = max(ans, helper(j, n, nums, k, dp));
        }

        return dp[i] = ans == INT_MIN ? nums[i] : ans + nums[i];
    }
};

//Bottom Up DP with multiset
//Time complexity - O(nlogk)
//Space complexity - O(n)
class Solution {
public:
    int maxResult(vector<int>& nums, int k)
    {
        int n = nums.size();
        vector<int>dp(n, -1);
        multiset<int, greater<int>>s;
        dp[n - 1] = nums[n - 1];
        s.insert(dp[n - 1]);

        for (int i = n - 2; i >= 0; i--)
        {
            if (i + k + 1 < n)   s.erase(s.find(dp[i + k + 1]));
            dp[i] = *s.begin() + nums[i];
            s.insert(dp[i]);
        }

        return dp[0];
    }
};

//Using monotonic queue - Deque
//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    int maxResult(vector<int>& nums, int k)
    {
        int n = nums.size();
        deque<int>q;
        vector<int>dp(n);
        dp[n - 1] = nums[n - 1];
        q.push_back(n - 1);

        for (int i = n - 2; i >= 0; i--)
        {
            if (!q.empty() && q.front() > min(n - 1, i + k))  q.pop_front();
            dp[i] = nums[i] + dp[q.front()];
            while (!q.empty() && dp[i] >= dp[q.back()])    q.pop_back();
            q.push_back(i);
        }

        return dp[0];
    }
};