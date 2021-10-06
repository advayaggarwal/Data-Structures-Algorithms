//Time complexity - O(n^3)
//Space complexity - O(n^2)
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

    int minPartitions(string &s, int i, int j, vector<vector<int>>&dp)
    {
        if (i >= j || isPalindrome(s, i, j)) return 0;

        if (dp[i][j] != -1)  return dp[i][j];

        int ans = INT_MAX;

        for (int k = i; k < j; k++)
        {
            int temp_ans = minPartitions(s, i, k, dp) + minPartitions(s, k + 1, j, dp) + 1;

            ans = min(ans, temp_ans);
        }

        return dp[i][j] = ans;
    }


    int minCut(string s) {

        int n = s.size();

        if (isPalindrome(s, 0, n - 1)) return 0;

        vector<vector<int>>dp(n + 1, vector<int>(n + 1, -1));

        return minPartitions(s, 0, n - 1, dp);

    }
};

//Time complexity - O(n^2)
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