//Recursion
//Time complexity - O(n^3)
//Space complexity - O(n)
class Solution {
public:
    int countSubstrings(string s)
    {
        return recursive(s);
    }

    int recursive(string& s) {
        int count = 0;
        for (int i = 0; i < s.size(); ++i) {
            for (int j = i; j < s.size(); ++j) {
                count += helper(s, i, j);
            }
        }
        return count;
    }

    // return 1 if s[i..j] is palindromic, 0 otherwise.
    int helper(string& s, int i, int j) {
        if (i >= j) return 1;
        return s[i] == s[j] ? helper(s, i + 1, j - 1) : 0;
    }
};

//Top Down DP - Memoization
//Time complexity - O(n^2)
//Space complexity - O(n^2)
class Solution {
public:
    int countSubstrings(string s)
    {
        return memoization(s);
    }

    int memoization(string& s) {
        vector<vector<int>> mem(s.size(), vector<int>(s.size(), -1));
        int count = 0;
        for (int i = 0; i < s.size(); ++i) {
            for (int j = i; j < s.size(); ++j) {
                count += solve(mem, s, i, j);
            }
        }
        return count;
    }

    int solve(vector<vector<int>>& mem, string& s, int i, int j) {
        if (i >= j) return 1;
        if (mem[i][j] >= 0) return mem[i][j];
        return mem[i][j] = s[i] == s[j] ? solve(mem, s, i + 1, j - 1) : 0;
    }
};

//Bottom Up DP
//Time complexity - O(n^2)
//Space complexity - O(n^2)
class Solution {
public:
    int countSubstrings(string s)
    {
        return tabulation(s);
    }

    int tabulation(string& s) {
        vector<vector<int>> tab(s.size(), vector<int>(s.size()));
        int count = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            for (int j = i; j < s.size(); ++j) {
                if (i == j) {
                    tab[i][j] = 1;
                } else if (i + 1 == j) {
                    tab[i][j] = s[i] == s[j] ? 1 : 0;
                } else {
                    tab[i][j] = s[i] == s[j] ? tab[i + 1][j - 1] : 0;
                }
                count += tab[i][j];
            }
        }
        return count;
    }
};

//Bottom Up DP
//Time complexity - O(n^2)
//Space complexity - O(n^2)
class Solution {
public:
    int countSubstrings(string s)
    {
        int n = s.size(), count = 0;
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
        int n = s.size(), count = 0;

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
        for (int mid = 0; mid < n; mid++)
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

class Solution {
public:
    int countSubstrings(string s)
    {
        int n = s.size(), count = 0;

        for (int mid = 0; mid < n; mid++)
        {
            //Odd length palindromes
            for (int x = 0; mid - x >= 0 && mid + x < n; x++)
            {
                if (s[mid - x] != s[mid + x])  break;
                count++;
            }

            //Even length palindromes
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
class Solution {
public:
    int countSubstrings(string s)
    {
        int n = s.size(), count = 0;
        for (int mid = 0; mid < n; mid++)
        {
            //odd length
            for (int x = 0; mid - x >= 0 && mid + x < n && s[mid - x] == s[mid + x]; x++) count++;
            //even length
            for (int x = 1; mid - x + 1 >= 0 && mid + x < n && s[mid - x + 1] == s[mid + x]; x++)    count++;
        }
        return count;
    }
};