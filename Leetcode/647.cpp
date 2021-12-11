//Bottom Up DP
//Time complexity - O(n^2)
//Space complexity - O(n^2)
class Solution {
public:
    int countSubstrings(string s)
    {
        int n = s.size();

        int count = 0;
        vector<vector<bool>>dp(n, vector<bool>(n, false));

        for (int gap = 0; gap < n; gap++)
        {
            for (int i = 0, j = gap; j < n; i++, j++)
            {
                if (gap == 0)  dp[i][j] = true;
                else if (gap == 1) dp[i][j] = (s[i] == s[j]) ? true : false;
                else
                {
                    dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];
                }

                if (dp[i][j])    count++;
            }
        }

        return count;
    }
};

//Stretching from the middle
//Time complexity - O(n^2)
//Space complexity - O(1)
class Solution {
public:
    int countSubstrings(string s)
    {
        int n = s.size();
        int count = 0;
        int curr_len = 0;

        //Odd length palindromes
        for (int mid = 0; mid < n; mid++)
        {
            for (int x = 0; mid - x >= 0 && mid + x < n; x++)
            {
                if (s[mid - x] != s[mid + x])  break;

                count++;
            }
        }

        //Even length palindromes
        for (int mid = 0; mid < n - 1; mid++)
        {
            for (int x = 1; mid - x + 1 >= 0 && mid + x < n; x++)
            {
                if (s[mid - x + 1] != s[mid + x])  break;

                count++;
            }
        }

        return count;
    }
};

//Shorter version of the above code
int countSubstrings(string s) {
    int res = 0, n = s.length();
    for (int i = 0; i < n; i++) {
        for (int j = 0; i - j >= 0 && i + j < n && s[i - j] == s[i + j]; j++)res++; //substring s[i-j, ..., i+j]
        for (int j = 0; i - 1 - j >= 0 && i + j < n && s[i - 1 - j] == s[i + j]; j++)res++; //substring s[i-1-j, ..., i+j]
    }
    return res;
}
