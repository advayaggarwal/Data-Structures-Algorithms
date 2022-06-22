//Time complexity - O(N*M), where M is the number of queries
//Space complexity - O(N), N number of words are stored.
class Node {
public:
    char data;
    unordered_map<char, Node*>m;
    bool isTerminal;

    Node(char d)
    {
        data = d;
        isTerminal = false;
    }
};

class Trie {
public:
    Node *root;

    Trie()
    {
        root = new Node('\0');
    }

    void insert(string word)
    {
        Node *temp = root;
        for (char c : word)
        {
            if (temp->m.find(c) == temp->m.end())
            {
                temp->m[c] = new Node(c);
            }

            temp = temp->m[c];
        }

        temp->isTerminal = true;
    }

    bool search(string word, Node *temp)
    {
        for (int i = 0; i < word.size(); i++)
        {
            if (word[i] == '.')
            {
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    if (temp->m.find(ch) != temp->m.end() && search(word.substr(i + 1), temp->m[ch]))   return true;
                }

                return false;
            }

            else if (temp->m.find(word[i]) == temp->m.end())   return false;
            temp = temp->m[word[i]];
        }

        return temp->isTerminal;
    }
};

class WordDictionary {
public:
    Trie t;
    WordDictionary() {
    }

    void addWord(string word)
    {
        t.insert(word);
    }

    bool search(string word)
    {
        Node *temp = t.root;
        return t.search(word, temp);
    }
};