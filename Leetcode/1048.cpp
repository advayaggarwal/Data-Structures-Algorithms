//LIS pattern
//Time complexity - O(n^2 * k), where k is max string length
//Space complexity - O(n)
class Solution {
public:
    int longestStrChain(vector<string>& words)
    {
        int n = words.size(), ans = 0;
        sort(words.begin(), words.end(), [&](string & s1, string & s2) { //sorting based on length
            return s1.size() < s2.size();
        });
        vector<int>dp(n, 1);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (predecessor(words[i], words[j]) && dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                }
            }

            ans = max(ans, dp[i]);
        }

        return ans;
    }

    bool predecessor(string &s1, string &s2)
    {
        if (s1.size() != s2.size() + 1)  return false;

        int i = 0, j = 0, n1 = s1.size(), n2 = n1 - 1;

        while (i < n1)
        {
            if (s1[i] == s2[j])
            {
                i++;
                j++;
            }

            else    i++;
        }

        return i == n1 && j == n2;
    }
};

//Time complexity - O(nlog(n) + nll), where l is max string length, O(nll): n for each loop, l for inner loop and l for string concatenation.
//Space complexity - O(n)
class Solution {
public:
    int longestStrChain(vector<string> &words)
    {
        unordered_map<string, int> dp;
        int res = 1;
        sort(words.begin(), words.end(), [&](const string & l, const string & r) {
            return l.size() < r.size();
        });

        for (string word : words)
        {
            dp[word] = 1;
            for (int i = 0; i < word.size(); i++) //finding all predecessors by removing ith char at once
            {
                string prev = word.substr(0, i) + word.substr(i + 1);
                if (dp.find(prev) != dp.end())
                {
                    dp[word] = max(dp[word], dp[prev] + 1);
                    res = max(res, dp[word]);
                }
            }
        }

        return res;
    }
};