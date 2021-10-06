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

        int ans1 = 0, ans2 = 0;

        if (s[index] == '0') return 0;

        ans1 = helper(s, index + 1, dp);

        if (index < s.size() - 1)
        {
            int no = stoi(string(1, s[index]) + string(1, s[index + 1]));

            if (no > 0 and no <= 26)
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
            int op1 = 0, op2 = 0;

            if (s[i] == '0') dp[i] = 0;
            else
            {
                op1 = dp[i + 1];

                if (i < n - 1)
                {
                    int no = stoi(string(1, s[i]) + string(1, s[i + 1]));
                    if (no > 0 and no <= 26)  op2 = dp[i + 2];
                }

                dp[i] = op1 + op2;
            }
        }

        return dp[0];
    }

};