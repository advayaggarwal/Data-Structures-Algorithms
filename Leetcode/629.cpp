//Top Down DP
//Time complexity - O(n*n*min(n, k))
//Space complexity - O(n*k)
class Solution {
public:
    int mod = 1e9 + 7;
    int kInversePairs(int n, int k)
    {
        vector<vector<int>>dp(n + 1, vector<int>(k + 1, -1));
        return helper(n, k, dp);
    }

    int helper(int n, int k, vector<vector<int>>&dp)
    {
        if (n == 0)  return 0;
        if (k == 0)  return 1;
        if (dp[n][k] != -1)  return dp[n][k];

        int count = 0;
        for (int i = 0; i <= min(k, n - 1); i++)
        {
            count = (count + helper(n - 1, k - i, dp)) % mod;
        }

        return dp[n][k] = count;
    }
};

//Bottom Up DP
//Time complexity - O(n*n*min(n, k))
//Space complexity - O(n*k)
class Solution {
public:
    int kInversePairs(int n, int k)
    {
        int dp[1001][1001] = { 1 };
        for (int N = 1; N <= n; N++)
        {
            for (int K = 0; K <= k; K++)
            {
                for (int i = 0; i <= min(K, N - 1); i++)
                    dp[N][K] = (dp[N][K] + dp[N - 1][K - i]) % 1000000007;
            }
        }

        return dp[n][k];
    }
};