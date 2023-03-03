//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    string greatestLetter(string s)
    {
        vector<bool>lower(26, false), upper(26, false);

        for (auto c : s)
        {
            if (c >= 'a' && c <= 'z')  lower[c - 'a'] = true;
            else upper[c - 'A'] = true;
        }

        for (int i = 25; i >= 0; i--)
        {
            if (lower[i] && upper[i])
            {
                string res;
                res += 'A' + i;
                return res;
            }
        }

        return "";
    }
};