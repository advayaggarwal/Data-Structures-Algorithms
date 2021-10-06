class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string>ans;
        vector<vector<string>>res;

        helper(s, 0, s.size(), ans, res);
        return res;
    }

    void helper(string &s, int index, int n, vector<string>&ans, vector<vector<string>>&res)
    {
        if (index == n)
        {
            res.push_back(ans);
            return;
        }

        for (int i = index; i < n; i++)
        {
            if (isPalindrome(s, index, i))
            {
                ans.push_back(string(s, index, (i - index + 1)));
                helper(s, i + 1, n, ans, res);
                ans.pop_back();
            }
        }
    }

    bool isPalindrome(string &s, int i, int j)
    {
        while (i < j)
        {
            if (s[i++] != s[j--])   return false;
        }

        return true;
    }

};