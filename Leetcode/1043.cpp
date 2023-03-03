//Top Down DP
//Time complexity - O(n*k)
//Space complexity - O(n)
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k)
    {
        vector<int>dp(arr.size(), -1);
        return helper(0, k, arr, dp);
    }

    int helper(int i, int k, vector<int>&arr, vector<int>&dp)
    {
        if (i == arr.size()) return 0;
        if (dp[i] != -1) return dp[i];

        int ans = INT_MIN, maxi = INT_MIN;
        for (int ind = i; ind < min((int)arr.size(), i + k); ind++)
        {
            maxi = max(maxi, arr[ind]);
            ans = max(ans, maxi * (ind - i + 1) + helper(ind + 1, k, arr, dp));
        }

        return dp[i] = ans;
    }
};

//Bottom Up DP
//Time complexity - O(n*k)
//Space complexity - O(n)
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k)
    {
        int n = arr.size();
        vector<int>dp(n + 1);

        for (int i = n - 1; i >= 0; i--)
        {
            int ans = INT_MIN, maxi = INT_MIN;
            for (int ind = i; ind < min(n, i + k); ind++)
            {
                maxi = max(maxi, arr[ind]);
                ans = max(ans, maxi * (ind - i + 1) + dp[ind + 1]);
            }

            dp[i] = ans;
        }
        return dp[0];
    }
};