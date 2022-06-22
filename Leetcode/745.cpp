//Hashmap - Storing all the combinations of prefixes and suffixes in an unordered map
class WordFilter {
public:
    unordered_map<string, int>m;
    WordFilter(vector<string>& words) //O(n*l*l), where n is #words and l is maximum word size
    {
        for (int i = 0; i < words.size(); i++)
        {
            string w = words[i];
            for (int j = 0; j < w.size(); j++) //prefix loop
            {
                string prefix = w.substr(0, j + 1);
                for (int k = 0; k < w.size(); k++)
                {
                    string suffix = w.substr(k);
                    string key = prefix + "#" + suffix;
                    m[key] = i;
                }
            }
        }
    }

    int f(string prefix, string suffix) //O(1)
    {
        string s = prefix + "#" + suffix;
        if (m.count(s))  return m[s];
        return -1;
    }
};

//Using Trie
class TrieNode {
public:
    char c;
    int index;
    unordered_map<char, TrieNode*> children;

    TrieNode(char c)
    {
        this->c = c;
    }
};

class Trie {
public:
    TrieNode *root;
    Trie() {
        root = new TrieNode('\0');
    }

    void insert(string word, int index) {
        TrieNode *temp = root;

        for (char ch : word)
        {
            if (!temp->children.count(ch))
            {
                temp->children[ch] = new TrieNode(ch);
            }
            temp = temp->children[ch];
            temp->index = index; //updating the index
        }
    }

    int startsWith(string word) {
        TrieNode *temp = root;
        for (char ch : word)
        {
            if (!temp->children[ch]) return -1;
            temp = temp->children[ch];
        }

        return temp->index;
    }
};

class WordFilter {
public:
    Trie t;
    WordFilter(vector<string>& words) { //O(n*l*l)
        for (int i = 0; i < words.size(); i++)
        {
            string w = words[i];
            for (int j = 0; j < w.size(); j++)
            {
                string suffix = w.substr(j);
                t.insert(suffix + "#" + w, i);
            }
        }
    }

    int f(string prefix, string suffix) { //O(l)
        return t.startsWith(suffix + "#" + prefix);
    }
};