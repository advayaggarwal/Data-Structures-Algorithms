//Bottom Up DP
//Time complexity - O(n^2)
//Space complexity - O(n^2)
class Solution {
public:
    int mod = 1e9 + 7;
    int countOrders(int n)
    {
        vector<vector<int>>dp(n + 1, vector<int>(n + 1, -1));
        return totalWays(n, n, dp);
    }

    long long totalWays(int unpicked, int undelivered, vector<vector<int>>&dp)
    {
        if (unpicked == 0 && undelivered == 0)   return 1;
        if (unpicked < 0 or undelivered < 0 or unpicked > undelivered)   return 0;
        if (dp[unpicked][undelivered] != -1) return dp[unpicked][undelivered];

        long long ans = 0;
        ans += unpicked * totalWays(unpicked - 1, undelivered, dp);
        ans %= mod;

        ans += (undelivered - unpicked) * totalWays(unpicked, undelivered - 1, dp);
        ans %= mod;

        return dp[unpicked][undelivered] = ans;
    }
};

//Top Down DP
//Time complexity - O(n^2)
//Space complexity - O(n^2)
class Solution {
public:
    int mod = 1e9 + 7;
    int countOrders(int n)
    {
        vector<vector<long>>dp(n + 1, vector<long>(n + 1));
        for (int i = 0; i <= n; i++)
        {
            for (int j = i; j <= n; j++)
            {
                if (i == 0 && j == 0)
                {
                    dp[i][j] = 1;
                    continue;
                }

                long long ans = 0;
                if (i > 0) ans += i * dp[i - 1][j];
                ans %= mod;

                if (j > 0) ans += (j - i) * dp[i][j - 1];
                ans %= mod;

                dp[i][j] = ans;
            }
        }

        return dp[n][n];
    }
};

//Top Down DP with space optimisation
//Time complexity - O(n^2)
//Space complexity - O(n)
class Solution {
public:
    int mod = 1e9 + 7;
    int countOrders(int n)
    {
        vector<long>prev(n + 1);
        for (int i = 0; i <= n; i++)
        {
            vector<long>curr(n + 1);
            for (int j = i; j <= n; j++)
            {
                if (i == 0 && j == 0)
                {
                    curr[j] = 1;
                    continue;
                }

                long long ans = 0;
                if (i > 0) ans += i * prev[j];
                ans %= mod;

                if (j > 0) ans += (j - i) * curr[j - 1];
                ans %= mod;

                curr[j] = ans;
            }
            prev = curr;
        }

        return prev[n];
    }
};

//Permutations
//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    int mod = 1e9 + 7;
    int countOrders(int n)
    {
        long ans = 1;

        for (int i = 1; i <= n; i++)
        {
            ans *= i; //ways to arrange all pickups
            ans = ans * (2 * i - 1); //ways to arrange all deliveries
            ans %= mod;
        }
        return ans;
    }
};

//Probability
//Calculate (2N)! / 2^N and return it.
//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    int countOrders(int n) {
        long ans = 1;
        int MOD = 1e9 + 7;

        for (int i = 1; i <= 2 * n; ++i) {
            ans = ans * i;

            // We only need to divide the result by 2 n-times.
            // To prevent decimal results we divide after multiplying an even number.
            if (i % 2 == 0) {
                ans = ans / 2;
            }
            ans %= MOD;
        }
        return ans;
    }
};