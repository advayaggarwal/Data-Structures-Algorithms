//Time complexity - O(n)
//Space complexity - O(n)
/*
    dp[i] = dp[i-1] + dp[i-2] + 2*dp[i-3] + 2*dp[i-4] + ... + 2*dp[0];
    dp[0] = dp[1] = 1;
    dp[2] = 2;
*/

class Solution {
public:
    const int mod = 1e9 + 7;
    int numTilings(int n)
    {
        vector<int>dp(n + 1);
        dp[0] = dp[1] = 1;
        if (n >= 2)   dp[2] = 2;
        if (n >= 3)   dp[3] = 5;

        for (int i = 4; i <= n; i++)
        {
            dp[i] = 2 * (dp[i - 1]) % mod + (dp[i - 3]) % mod; //By solving above equation
            dp[i] %= mod;
        }

        return dp[n];
    }
};