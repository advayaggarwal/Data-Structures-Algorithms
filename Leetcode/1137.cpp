//Bottom Up DP
//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    int tribonacci(int n)
    {
        if (n <= 1)    return n;
        vector<int>dp(n + 1);
        dp[1] = dp[2] = 1;

        for (int i = 3; i <= n; i++) dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];

        return dp[n];
    }
};

//Bottom Up DP with constant space
//Time complexity - O(n)
//Space complexity - O(1), we need only 3 previous states
class Solution {
public:
    int tribonacci(int n)
    {
        if (n <= 1)    return n;

        int prev = 0, cur = 1, next = 1;

        for (int i = 3; i <= n; i++)
        {
            int temp = prev + cur + next;
            prev = cur;
            cur = next;
            next = temp;
        }

        return next;
    }
};