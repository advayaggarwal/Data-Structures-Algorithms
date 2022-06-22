//Time complexity - O(4^n * n), each digit can map to atmost 4 chars
//4^N for building every possible string combination and N to form the string by joining each character.
//Space complexity - O(n)
class Solution {
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string>res;
        if (digits.size() == 0)   return res;
        unordered_map<char, vector<char>>m;
        m['2'] = {'a', 'b', 'c'};
        m['3'] = {'d', 'e', 'f'};
        m['4'] = {'g', 'h', 'i'};
        m['5'] = {'j', 'k', 'l'};
        m['6'] = {'m', 'n', 'o'};
        m['7'] = {'p', 'q', 'r', 's'};
        m['8'] = {'t', 'u', 'v'};
        m['9'] = {'w', 'x', 'y', 'z'};

        string op = "";
        helper(m, digits, 0, res, op);
        return res;
    }

    void helper(unordered_map<char, vector<char>>&m, string &digits, int n,  vector<string>&res, string &op)
    {
        if (n == digits.size())
        {
            res.push_back(op);
            return;
        }

        for (auto &ele : m[digits[n]])
        {
            op.push_back(ele);
            helper(m, digits, n + 1, res, op);
            op.pop_back();
        }
    }
};

//Time complexity - O(4^n * n), each digit can map to atmost 4 chars
//4^N for building every possible string combination and N to form the string by joining each character.
//Space complexity - O(n)
class Solution {
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string>res;
        if (digits.size() == 0)  return res;
        vector<string>m = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string op;
        helper(0, digits, m, op, res);

        return res;
    }

    void helper(int i, string &digits, vector<string>&m, string &op, vector<string>&res)
    {
        if (i == digits.size())
        {
            res.push_back(op);
            return;
        }

        int d = digits[i] - '0';
        for (int j = 0; j < m[d].size(); j++)
        {
            op.push_back(m[d][j]);
            helper(i + 1, digits, m, op, res);
            op.pop_back();
        }
    }
};