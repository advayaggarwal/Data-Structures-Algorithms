//Multistaged DP
//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    int dp[200005][3];
    int minimumTime(string s)
    {
        int n = s.size();
        memset(dp, -1, sizeof(dp));
        return helper(0, n, 0, s);
    }

    int helper(int i, int n, int state, string &s)
    {
        if (i == n)  return 0;
        if (dp[i][state] != -1)  return dp[i][state];

        int ans = INT_MAX;

        for (int st = state; st < 3; st++)
        {
            if (st == 1)
            {
                if (s[i] == '1') ans = min(ans, 2 + helper(i + 1, n, st, s));
                else ans = min(ans, helper(i + 1, n, st, s));
            }

            else    ans = min(ans, 1 + helper(i + 1, n, st, s));
        }

        return dp[i][state] = ans;
    }
};