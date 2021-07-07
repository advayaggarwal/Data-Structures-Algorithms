// 2 Pointer Approach, just iterate over the string s, and if it is matching with a char in word, increment the pointer
//if that pointer reaches the end of the word, it means it can be formed

//Time complexity - O(n*m), where n = s.size(), m = words.size(), giving TLE
//Space complexity - O(1)
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int count = 0;

        for (string st : words)
        {
            int i = 0, j = 0;

            while (i != st.size() && j != s.size())
            {
                if (st[i] == s[j])
                {
                    i++;
                    j++;
                }

                else j++;
            }

            if (i == st.size()) count++;
        }

        return count;
    }
};

//Most efficient approach
// General Idea:
// - Brute force checking will time out, we need efficent way to look up words
// - Create an vector/map that stores indices for each character a-z in S
// - Then for each word, do a binary search for next index for current character in word
//   that is greater than the index we last found for the last character
// - If it doesn't exist, word doesn't exist, otherwise continue to search for word

//Time complexity - O(n + m*(k*logn)), where n = s.size(), m = words.size(), k = max(words[i].size) giving TLE
// n for building the map, klogn for searching the word and total there are m words
//Space complexity - O(n)

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char, vector<int>>m;
        int n = s.size();

        for (int i = 0; i < n; i++)
        {
            m[s[i]].push_back(i);
        }

        int count = 0;

        for (auto word : words)
        {
            int last_index = -1;
            bool found = true;
            for (auto c : word)
            {
                auto it = upper_bound(m[c].begin(), m[c].end(), last_index);

                if (it == m[c].end())
                {
                    found = false;
                    break;
                }

                else last_index = *it;
            }

            if (found)   count++;

        }
        return count;
    }
};

//Same as above just used vector instead of map as we know string only contains lowercase english alphabets
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>>alpha(26);
        int n = s.size();

        for (int i = 0; i < n; i++)
        {
            alpha[s[i] - 'a'].push_back(i);
        }

        int count = 0;

        for (auto word : words)
        {
            int last_index = -1;
            bool found = true;
            for (auto c : word)
            {
                auto it = upper_bound(alpha[c - 'a'].begin(), alpha[c - 'a'].end(), last_index);

                if (it == alpha[c - 'a'].end())
                {
                    found = false;
                    break;
                }

                else last_index = *it;
            }

            if (found)   count++;

        }
        return count;
    }
};
