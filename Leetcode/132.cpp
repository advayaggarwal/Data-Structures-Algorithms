//Top Down DP
//Time complexity - O(n^3)
//Space complexity - O(n)
class Solution {
public:
    bool isPalindrome(string &s, int i, int j)
    {
        while (i < j)
        {
            if (s[i++] != s[j--])    return false;
        }

        return true;
    }

    int minPartitions(string &s, int i, int n, vector<int>&dp)
    {
        if (i >= n) return 0;

        if (dp[i] != -1)  return dp[i];

        int ans = INT_MAX;

        for (int k = i; k < n; k++)
        {
            if (isPalindrome(s, i, k))
            {
                ans = min(ans, minPartitions(s, k + 1, n, dp));
            }
        }

        return dp[i] = ans + 1;
    }

    int minCut(string s) {

        int n = s.size();

        if (isPalindrome(s, 0, n - 1)) return 0;

        vector<int>dp(n + 1, -1);

        return minPartitions(s, 0, n, dp) - 1; //it is considering partition after last element also that's why we are
        //subtracting 1, eg- abccbc -> a|bccb|c|
    }
};

//Bottom Up DP
//Time complexity - O(n^3)
//Space complexity - O(n)
class Solution {
public:
    int minCut(string s)
    {
        int n = s.size();
        vector<int>dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            int ans = INT_MAX;
            for (int j = i; j < n; j++)
            {
                if (isPalindrome(s, i, j))
                {
                    ans = min(ans, dp[j + 1]);
                }
            }

            dp[i] = ans + 1;
        }

        return dp[0] - 1;
    }

    bool isPalindrome(string &s, int i, int j)
    {
        while (i < j)
        {
            if (s[i++] != s[j--])    return false;
        }

        return true;
    }
};

//We can precompute whether the string i...j is palindrome or not
//Time complexity - O(n^2)
//Space complexity - O(n^2)
class Solution {
public:
    int minCut(string s)
    {
        int n = s.size();
        vector<int>dp(n + 1, 0);
        vector<vector<bool>>isPalindrome(n, vector<bool>(n, false));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i; j < n; j++)
            {
                if (s[i] == s[j])
                {
                    if (j - i + 1 <= 2)  isPalindrome[i][j] = true;
                    else isPalindrome[i][j] = isPalindrome[i + 1][j - 1];
                }
            }
        }

        for (int i = n - 1; i >= 0; i--)
        {
            int ans = INT_MAX;
            for (int j = i; j < n; j++)
            {
                if (isPalindrome[i][j])
                {
                    ans = min(ans, dp[j + 1]);
                }
            }

            dp[i] = ans + 1;
        }

        return dp[0] - 1;
    }
};