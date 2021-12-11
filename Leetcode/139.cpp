//Recursion
//Time complexity - O(2^n)
//Space complexity - O(n)
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        unordered_set<string>m;
        for (string str : wordDict)   m.insert(str);

        return helper(0, s, m);
    }

    bool helper(int i, string &s, unordered_set<string>&m)
    {
        if (i == s.size()) return true;

        string temp;

        for (int j = i; j < s.size(); j++)
        {
            temp += s[j];
            if (m.find(temp) != m.end())
            {
                if (helper(j + 1, s, m))   return true;
            }
        }

        return false;
    }
};

//Top Down DP
//Time complexity - O(n^2)
//Space complexity - O(n)
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        unordered_set<string>m;
        for (string str : wordDict)   m.insert(str);

        int n = s.size();
        vector<int>dp(n, -1);

        return helper(0, s, m, dp);
    }

    int helper(int i, string &s, unordered_set<string>&m, vector<int>&dp)
    {
        if (i == s.size()) return 1;

        if (dp[i] != -1)  return dp[i];

        string temp;

        for (int j = i; j < s.size(); j++)
        {
            temp += s[j];
            if (m.find(temp) != m.end())
            {
                if (helper(j + 1, s, m, dp))   return dp[i] = 1;
            }
        }

        return dp[i] = 0;
    }
};

//Bottom Up DP
//Time complexity - O(n^2)
//Space complexity - O(n)
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        int n = s.size();

        unordered_set<string>m;
        for (string k : wordDict) m.insert(k);

        vector<int>dp(n + 1, 0); //dp[i] represents if substring from i till n can be segmented or not
        dp[n] = 1;

        for (int i = n - 1; i >= 0; i--)
        {
            string temp;
            for (int j = i; j < n; j++)
            {
                temp += s[j];
                if (m.find(temp) != m.end())
                {
                    if (dp[j + 1])
                    {
                        //substring from i till j is present and remaining part(j+1...n) can be segmented, so i...n can also be segmented
                        dp[i] = 1;
                        break;
                    }
                }
            }
        }

        return dp[0];
    }
};