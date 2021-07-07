class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        int ans = 0;
        unordered_map<char, int>m{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == 'I' && s[i + 1] == 'V')   ans -= m[s[i]];
            else if (s[i] == 'I' && s[i + 1] == 'X')   ans -= m[s[i]];
            else if (s[i] == 'X' && s[i + 1] == 'L')   ans -= m[s[i]];
            else if (s[i] == 'X' && s[i + 1] == 'C')   ans -= m[s[i]];
            else if (s[i] == 'C' && s[i + 1] == 'D')   ans -= m[s[i]];
            else if (s[i] == 'C' && s[i + 1] == 'M')   ans -= m[s[i]];
            else ans += m[s[i]];
        }

        ans += m[s[n - 1]];
        return ans;
    }
};



class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        int ans = 0;
        unordered_map<char, int>m{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        for (int i = 0; i < n - 1; i++)
        {
            if (m[s[i]] < m[s[i + 1]]) ans -= m[s[i]];
            else ans += m[s[i]];
        }

        ans += m[s[n - 1]];
        return ans;
    }
};