//Brute force
//Time complexity - O(n^3)
//Space complexity - O(1)
class Solution {
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        string res;

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                string str = s.substr(i, j - i + 1);
                if (isPalindrome(str) && str.size() > res.size())    res = str; //O(n)
            }
        }

        return res;
    }

    bool isPalindrome(string s)
    {
        int i = 0, j = s.size() - 1;

        while (i < j)
        {
            if (s[i++] != s[j--])    return false;
        }

        return true;
    }
};

//Bottom Up DP, filling diagonal wise
//Time complexity - O(n^2)
//Space complexity - O(n^2)
class Solution {
public:
    string longestPalindrome(string s)
    {
        int n = s.size();

        string res;
        int start = 0, end = 0;
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

                if (dp[i][j])
                {
                    start = i;
                    end = j;
                }
            }
        }

        res = s.substr(start, end - start + 1);
        return res;
    }
};

//Bottom Up DP
//Time complexity - O(n^2)
//Space complexity - O(n^2)
class Solution {
public:
    string longestPalindrome(string s)
    {
        int n = s.size();

        int start = 0, current_length = 0;
        vector<vector<bool>>dp(n, vector<bool>(n, false));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i; j < n; j++)
            {
                if ((s[i] == s[j]) && (j - i < 2 || dp[i + 1][j - 1]))
                {
                    dp[i][j] = true;

                    if (current_length < j - i + 1)
                    {
                        current_length = j - i + 1;
                        start = i;
                    }
                }
            }
        }

        string res = s.substr(start, current_length);
        return res;
    }
};

//Stretching from the middle
//Time complexity - O(n^2)
//Space complexity - O(1)
class Solution {
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        int current_length = 0;
        int start = 0;

        for (int mid = 0; mid < n; mid++)
        {
            //Odd length Substring
            for (int x = 0; mid - x >= 0 && mid + x < n; x++)
            {
                if (s[mid - x] != s[mid + x])    break;

                int len = 2 * x + 1;
                if (len > current_length)
                {
                    current_length = len;
                    start = mid - x;
                }
            }

            //Even length substring
            for (int x = 1; mid - x + 1 >= 0 && mid + x < n; x++)
            {
                if (s[mid - x + 1] != s[mid + x])  break;

                int len = 2 * x;
                if (len > current_length)
                {
                    current_length = len;
                    start = mid - x + 1;
                }
            }
        }

        return s.substr(start, current_length);
    }
};