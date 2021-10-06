//Recursion with Memoization
//Time complexity - O(n^2)
//Space complexity - O(n)

class Solution {
public:
    int numTrees(int n) {
        vector<int>dp(n + 1, -1);

        return uniqueBST(n, dp);
    }

    int uniqueBST(int n, vector<int>&dp)
    {
        if (n == 0 or n == 1)    return 1;

        if (dp[n] != -1)   return dp[n];

        int count = 0;
        for (int i = 1; i <= n; i++)
        {
            count += uniqueBST(i - 1, dp) * uniqueBST(n - i, dp);
        }

        return dp[n] = count;
    }
};


//Tabulation
//Time complexity - O(n^2)
//Space complexity - O(n)

class Solution {
public:
    int numTrees(int n) {

        if (n == 1)    return 1;

        vector<int>dp(n + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                dp[i] += (dp[j - 1] * dp[i - j]);
            }
        }
        return dp[n];
    }
};