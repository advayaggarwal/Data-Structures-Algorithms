//Top Down DP
//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    int numDecodings(string s) {

        vector<int>dp(s.size() + 1, -1);
        return  helper(s, 0, dp);
    }

    int helper(string &s, int index, vector<int>&dp)
    {
        if (index >= s.size())   return 1;
        if (dp[index] != -1)   return dp[index];

        if (s[index] == '0') return 0;

        int ans1 = helper(s, index + 1, dp);
        int ans2 = 0;

        if (index < s.size() - 1)
        {
            int no = (s[index] - '0') * 10 + (s[index + 1] - '0');

            if (no >= 10 and no <= 26)
            {
                ans2 = helper(s, index + 2, dp);
            }
        }

        return dp[index] = ans1 + ans2;
    }
};

//Bottom Up DP
//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    int numDecodings(string s) {

        int n = s.size();
        vector<int>dp(n + 1, 0);

        dp[n] = 1;

        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == '0') dp[i] = 0;
            else
            {
                dp[i] = dp[i + 1];

                if (i < n - 1)
                {
                    int no = (s[i] - '0') * 10 + (s[i + 1] - '0');
                    if (no >= 10 and no <= 26)  dp[i] += dp[i + 2];
                }
            }
        }

        return dp[0];
    }
};

//Bottom Up DP with space optimisation
//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    int numDecodings(string s) {

        int n = s.size();
        int curr = 0, next = 1, nextNext = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == '0') curr = 0;
            else
            {
                curr = next;

                if (i < n - 1)
                {
                    int no = (s[i] - '0') * 10 + (s[i + 1] - '0');
                    if (no >= 10 and no <= 26)  curr += nextNext;
                }
            }

            nextNext = next;
            next = curr;
        }

        return curr;
    }
};