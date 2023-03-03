//Time complexity - O(n^2*w), where n is number of words and k is word length
//Space complexity - O(1)
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words)
    {
        int n = words.size();
        vector<vector<int>>res;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)  continue;

                string word = words[i] + words[j];
                if (isPalindrome(word))  res.push_back({i, j});
            }
        }

        return res;
    }

    bool isPalindrome(string &s)
    {
        int i = 0, j = s.size() - 1;
        while (i < j)
        {
            if (s[i++] != s[j--])    return false;
        }

        return true;
    }
};

//Time complexity - O(n*w^2), where n is number of words and k is word length
//Space complexity - O(n*w)
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> dict;
        vector<vector<int>> ans;
        // build dictionary
        for (int i = 0; i < words.size(); i++) {
            string key = words[i];
            reverse(key.begin(), key.end());
            dict[key] = i;
        }
        // edge case: if empty string "" exists, find all palindromes to become pairs ("", self)
        if (dict.find("") != dict.end()) {
            for (int i = 0; i < words.size(); i++) {
                if (i == dict[""]) continue;
                if (isPalindrome(words[i])) ans.push_back({dict[""], i}); // 1) if self is palindrome, here ans covers concatenate("", self)
            }
        }

        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].size(); j++) {
                string left = words[i].substr(0, j);
                string right = words[i].substr(j, words[i].size() - j);

                if (dict.find(left) != dict.end() && isPalindrome(right) && dict[left] != i) {
                    ans.push_back({i, dict[left]});     // 2) when j = 0, left = "", right = self, so here covers concatenate(self, "")
                }

                if (dict.find(right) != dict.end() && isPalindrome(left) && dict[right] != i) {
                    ans.push_back({dict[right], i});
                }
            }
        }

        return ans;
    }

    bool isPalindrome(string str) {
        int i = 0;
        int j = str.size() - 1;

        while (i < j) {
            if (str[i++] != str[j--]) return false;
        }

        return true;
    }
};

class Solution {
public:
    bool isPalindrome(string& s, int l, int r) {
        while (l < r)
            if (s[l++] != s[r--])
                return false;

        return true;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        unordered_map<string, int> pool;
        set<int> mySet;

        for (int i = 0; i < words.size(); ++i) {
            pool[words[i]] = i;
            mySet.insert(words[i].size());
        }

        for (int i = 0; i < words.size(); ++i) {
            string s = words[i];
            int len = s.size();
            reverse(s.begin(), s.end());

            if (pool.count(s) && pool[s] != i) {
                res.push_back({i, pool[s]});
            }

            auto a = mySet.find(len);
            for (auto it = mySet.begin(); it != a; ++it) {
                int d = *it;
                if (isPalindrome(s, 0, len - d - 1) && pool.count(s.substr(len - d))) {
                    res.push_back({i, pool[s.substr(len - d)]});
                }
                if (isPalindrome(s, d, len - 1) && pool.count(s.substr(0, d))) {
                    res.push_back({pool[s.substr(0, d)], i});
                }
            }
        }

        return res;
    }
};