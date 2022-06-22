//Using Trie
//Time complexity -  O(nlogn + m)
//Space complexity - O(1)
class TrieNode {
public:
    char data;
    vector<int>index;
    TrieNode *children[26];

    TrieNode(char d)
    {
        data = d;
        for (int i = 0; i < 26; i++) children[i] = NULL;
    }
};

class Trie {
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode('\0');
    }

    void insert(string word, int ind)
    {
        TrieNode *temp = root;
        for (char c : word)
        {
            if (!temp->children[c - 'a'])
            {
                temp->children[c - 'a'] = new TrieNode(c);
            }

            temp = temp->children[c - 'a'];
            temp->index.push_back(ind);
        }
    }

    vector<int> startsWith(string word)
    {
        TrieNode *temp = root;
        for (char c : word)
        {
            if (!temp->children[c - 'a'])  return {};
            temp = temp->children[c - 'a'];
        }

        return temp->index;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord)
    {
        sort(products.begin(), products.end());
        Trie t;
        for (int i = 0; i < products.size(); i++)  t.insert(products[i], i);

        vector<vector<string>>res(searchWord.size());
        string word;
        for (int i = 0; i < searchWord.size(); i++)
        {
            word += searchWord[i];
            vector<int>ans = t.startsWith(word);
            for (int j = 0; j < min(ans.size(), 3); j++)  res[i].push_back(products[ans[j]]);
        }

        return res;
    }
};

//Using Binary Search
//Time complexity -  O(nlogn + mlogn)
//Space complexity - O(1)
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord)
    {
        sort(products.begin(), products.end());
        int n = searchWord.size(), m = products.size(), bstart = 0;
        vector<vector<string>>res(n);
        string prefix;
        for (int i = 0; i < n; i++)
        {
            prefix += searchWord[i];
            int start = lower_bound(products.begin() + bstart, products.end(), prefix) - products.begin();

            for (int j = start; j < min(start + 3, m) && isPrefix(prefix, products[j]); j++)
            {
                res[i].push_back(products[j]);
            }
            /*
            Another optimization that can be done is reducing the binary search space to current start index .
            (This is due to the fact that adding more chars to the prefix will make the next search result's
            index be at least > current search's index).
            */
            bstart = start;
        }

        return res;
    }

    bool isPrefix(string prefix, string product)
    {
        for (int i = 0; i < prefix.size(); i++)
        {
            if (prefix[i] != product[i]) return false;
        }

        return true;
    }
};