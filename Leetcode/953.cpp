//Time complexity - O(k*nlogn),  where n is words.size() and k is average word size
//Space complexity - O(n*k)
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order)
    {
        int n = words.size();
        vector<string>temp;
        unordered_map<char, int>pos;
        for (int i = 0; i < n; i++)  temp.push_back(words[i]);

        for (int i = 0; i < 26; i++) pos[order[i]] = i;

        sort(temp.begin(), temp.end(), [&](string & w1, string & w2) {
            for (int i = 0; i < min(w1.size(), w2.size()); i++)
            {
                if (w1[i] != w2[i])  return pos[w1[i]] < pos[w2[i]];
            }

            return w1.size() < w2.size();
        });

        return temp == words;
    }
};


//Time complexity - O(k*n),  where n is words.size() and k is average word size
//Space complexity - O(26)
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order)
    {
        int n = words.size();
        unordered_map<char, int>pos; //can use 26 size vector instead of map

        for (int i = 0; i < 26; i++) pos[order[i]] = i;

        for (int i = 0; i < n - 1; i++)
        {
            if (!compare(words[i], words[i + 1], pos))  return false;
        }

        return true;
    }

    bool compare(string &word1, string &word2, unordered_map<char, int>&pos)
    {
        for (int i = 0; i < min(word1.size(), word2.size()); i++)
        {
            if (pos[word1[i]] > pos[word2[i]])   return false;
            else if (pos[word1[i]] < pos[word2[i]])  return true;
        }

        return word1.size() <= word2.size();
    }
};

//Time complexity - O(k*n),  where n is words.size() and k is average word size
//Space complexity - O(1)
class Solution {
public:
    bool isAlienSorted(vector<string> words, string order)
    {
        int mapping[26];
        for (int i = 0; i < 26; i++)
            mapping[order[i] - 'a'] = i;
        for (string &w : words)
            for (char &c : w)
                c = mapping[c - 'a'];

        return is_sorted(words.begin(), words.end());
    }
};