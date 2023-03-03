//Time complexity - O(m*n), where m is the size of vector and n is the size of smallest string
//Space complexity - O(1)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        int n = strs.size();
        if (n == 0)  return "";
        string res;

        int index = 0;

        for (char c : strs[0])
        {
            for (int i = 1; i < n; i++)
            {
                if (index >= strs[i].size() or strs[i][index] != c)    return res;
            }
            res += c;
            index++;
        }

        return res;
    }
};

//Time complexity - O(m*n), where m is the size of vector and n is the size of smallest string
//Space complexity - O(1)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        string prefix = strs[0];

        for (int i = 0; i < strs.size() - 1; i++)
        {
            string word1 = strs[i], word2 = strs[i + 1];
            string temp;
            for (int j = 0; j < min(word1.size(), word2.size()); j++)
            {
                if (word1[j] == word2[j])    temp += word1[j];
                else break;
            }

            prefix = min(temp, prefix);
        }

        return prefix;
    }
};

//Using Trie
//Time complexity - O(m*n), where m is the size of vector and n is the size of smallest string
//Space complexity - O(m*n)
class TrieNode {
public:
    char data;
    TrieNode *children[26];
    int childCount;
    bool isTerminal;

    TrieNode(char c)
    {
        data = c;
        for (int i = 0; i < 26; i++) children[i] = NULL;
        childCount = 0;
        isTerminal = false;
    }
};

class Trie {
public:
    TrieNode *root;
    Trie(char c)
    {
        root = new TrieNode(c);
    }

    void insertUtil(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        if (root->children[index] == NULL) //character is not present in children of root
        {
            TrieNode *child = new TrieNode(word[0]);
            root->childCount++;
            root->children[index] = child;
        }

        insertUtil(root->children[index], word.substr(1));
    }

    void insert(string word)
    {
        insertUtil(root, word);
    }

    void lcp(string str, string &ans)
    {
        TrieNode *temp = root;
        for (int i = 0; i < str.size(); i++)
        {
            if (temp->isTerminal)    break;

            if (temp->childCount == 1)
            {
                ans += str[i];
                temp = temp->children[str[i] - 'a'];
            }

            else break;
        }
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        Trie *t = new Trie('\0');

        //insert all strings into the trie
        for (string s : strs)    t->insert(s);

        string first = strs[0], ans;
        t->lcp(first, ans);
        return ans;
    }
}; class TrieNode {
public:
    char data;
    TrieNode *children[26];
    int childCount;
    bool isTerminal;

    TrieNode(char c)
    {
        data = c;
        for (int i = 0; i < 26; i++) children[i] = NULL;
        childCount = 0;
        isTerminal = false;
    }
};

class Trie {
public:
    TrieNode *root;
    Trie(char c)
    {
        root = new TrieNode(c);
    }

    void insertUtil(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        if (root->children[index] == NULL) //character is not present in children of root
        {
            TrieNode *child = new TrieNode(word[0]);
            root->childCount++;
            root->children[index] = child;
        }

        insertUtil(root->children[index], word.substr(1));
    }

    void insert(string word)
    {
        insertUtil(root, word);
    }

    void lcp(string str, string &ans)
    {
        TrieNode *temp = root;
        for (int i = 0; i < str.size(); i++)
        {
            if (temp->isTerminal)    break;

            if (temp->childCount == 1)
            {
                ans += str[i];
                temp = temp->children[str[i] - 'a'];
            }

            else break;
        }
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        Trie *t = new Trie('\0');

        //insert all strings into the trie
        for (string s : strs)    t->insert(s);

        string first = strs[0], ans;
        t->lcp(first, ans);
        return ans;
    }
};