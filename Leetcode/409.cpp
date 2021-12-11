class Solution {
public:
    int longestPalindrome(string s)
    {
        unordered_map<char, int>m;

        for (char ch : s) m[ch]++;

        int count = 0;
        bool odd = false;

        for (auto p : m)
        {
            if (p.second % 2 == 0) count += p.second;

            else
            {
                count += (p.second - 1);
                odd = true;
            }
        }

        if (odd) count += 1;

        return count;
    }
};