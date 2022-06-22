//Time complexity - O(n)
//Space complexity - O(n)
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

//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    bool wordPattern(string pattern, string s)
    {
        istringstream ss(s);
        unordered_map<char, string>m;
        unordered_map<string, bool>used;
        vector<string>words;
        int n = pattern.size();
        for (string token; ss >> token;)   words.push_back(token);

        if (words.size() != n)   return false;

        for (int i = 0; i < n; i++)
        {
            if (m.count(pattern[i]))
            {
                if (m[pattern[i]] != words[i])   return false;
            }

            else
            {
                if (used.count(words[i]))  return false;

                m[pattern[i]] = words[i];
                used[words[i]] = true;
            }
        }


        return true;
    }
};