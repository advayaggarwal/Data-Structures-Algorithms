class Solution {
public:
    bool wordPattern(string pattern, string s)
    {
        istringstream ss(s);
        vector<int>pat_map(26, 0);

        unordered_map<string, int>m;
        int i = 0, n = pattern.size();

        for (string token; ss >> token; i++)
        {
            if (i == n || pat_map[pattern[i] - 'a'] != m[token]) return false;

            pat_map[pattern[i] - 'a'] = m[token] = i + 1;
        }

        return i == n;
    }
};