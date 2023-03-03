//Time Complexity : O(5^n), at each index we have maximum of 5 choices with us. There are total of n indices.
//Space Complexity : O(n), required for recursive stack. Max recursive depth at any point will be n
//The mappings are converted to from chars to integer as a:0, e:1, i:2, o:3, u:4, s:5
class Solution {
    const int MOD = 1e9 + 7;
    const vector<vector<int>> mappings{{1}, {0, 2}, {0, 1, 3, 4}, {2, 4}, {0}, {0, 1, 2, 3, 4}};
public:
    int countVowelPermutation(int n)
    {
        return helper(n, 5);
    }

    int helper(int n, int prev)
    {
        if (n == 0) return 1;

        int ans = 0;
        for (auto c : mappings[prev])    ans = (ans + helper(n - 1, c)) % MOD;
        return ans;
    }
};


//Top Down DP
//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
    const int MOD = 1e9 + 7;
    const vector<vector<int>> mappings{{1}, {0, 2}, {0, 1, 3, 4}, {2, 4}, {0}, {0, 1, 2, 3, 4}};
public:
    int countVowelPermutation(int n)
    {
        vector<vector<int>>dp(n + 1, vector<int>(6, -1));
        return helper(n, 5, dp);
    }

    int helper(int n, int prev, vector<vector<int>>&dp)
    {
        if (n == 0) return 1;
        if (dp[n][prev] != -1)   return dp[n][prev];

        int ans = 0;
        for (auto c : mappings[prev])    ans = (ans + helper(n - 1, c, dp)) % MOD;
        return dp[n][prev] = ans;
    }
};


//Bottom Up DP
//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
    const int MOD = 1e9 + 7;
    const vector<vector<int>> mappings{{1}, {0, 2}, {0, 1, 3, 4}, {2, 4}, {0}, {0, 1, 2, 3, 4}};
public:
    int countVowelPermutation(int N)
    {
        vector<vector<int>>dp(N + 1, vector<int>(6, 1));

        for (int n = 1; n <= N; n++)
        {
            for (int prev = 5; prev >= 0; prev--)
            {
                int ans = 0;
                for (auto c : mappings[prev])    ans = (ans + dp[n - 1][c]) % MOD;
                dp[n][prev] = ans;
            }
        }

        return dp[N][5];
    }
};


//Bottom Up DP with space optimisation
//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
    const int MOD = 1e9 + 7;
    const vector<vector<int>> mappings{{1}, {0, 2}, {0, 1, 3, 4}, {2, 4}, {0}, {0, 1, 2, 3, 4}};
public:
    int countVowelPermutation(int N)
    {
        vector<int>prevDp(6, 1), currDp(6, 1);

        for (int n = 1; n <= N; n++)
        {
            for (int prev = 5; prev >= 0; prev--)
            {
                int ans = 0;
                for (auto c : mappings[prev])    ans = (ans + prevDp[c]) % MOD;
                currDp[prev] = ans;
            }

            prevDp = currDp;
        }

        return currDp[5];
    }
};