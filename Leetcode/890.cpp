//Time complexity - O(n*m), where n is number of words and m is pattern length
//Space complexity - O(m)
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern)
    {
        vector<string>res;
        for (string word : words)
        {
            unordered_map<char, char>m1;
            unordered_map<char, char>m2;
            if (word.size() != pattern.size())   continue;
            int i;
            for (i = 0; i < word.size(); i++)
            {
                if (!m1.count(pattern[i]) && !m2.count(word[i]))
                {
                    m1[pattern[i]] = word[i];
                    m2[word[i]] = pattern[i];
                }
                else
                {
                    if (m1[pattern[i]] != word[i] or m2[word[i]] != pattern[i])    break;
                }
            }

            if (i == pattern.size()) res.push_back(word);
        }

        return res;
    }
};


//Time complexity - O(n*m), where n is number of words and m is pattern length
//Space complexity - O(1)
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern)
    {
        vector<string>res;
        for (string word : words)
        {
            vector<char>m1(26);
            vector<char>m2(26);
            if (word.size() != pattern.size())   continue;
            int i;
            for (i = 0; i < word.size(); i++)
            {
                if (m1[pattern[i] - 'a'] == '\0' && m2[word[i] - 'a'] == '\0')
                {
                    m1[pattern[i] - 'a'] = word[i];
                    m2[word[i] - 'a'] = pattern[i];
                }
                else
                {
                    if (m1[pattern[i] - 'a'] != word[i] or m2[word[i] - 'a'] != pattern[i])    break;
                }
            }

            if (i == pattern.size()) res.push_back(word);
        }

        return res;
    }
};