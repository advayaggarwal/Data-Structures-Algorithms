class Node {
public:
    char data;
    unordered_map<char, Node*>m;
    bool isTerminal;

    Node(char data)
    {
        this->data = data;
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

        for (char ch : word)
        {
            if (temp->m.find(ch) == temp->m.end()) //insert here
            {
                Node *n = new Node(ch);
                temp->m[ch] = n;
            }

            temp = temp->m[ch];
        }

        temp->isTerminal = true;
    }

    bool search(string word)
    {
        Node *temp = root;
        for (char ch : word)
        {
            if (temp->m.find(ch) == temp->m.end())    return false;
            temp = temp->m[ch];
        }

        return temp->isTerminal;
    }

    bool startsWith(string prefix)
    {
        Node *temp = root;
        for (char ch : prefix)
        {
            if (temp->m.find(ch) == temp->m.end())    return false;
            temp = temp->m[ch];
        }

        return true;
    }
};

//Instead of unordered_map used vector, as trie contains only lowercase english alphabets
class Node {
public:
    char data;
    vector<Node*>m;
    bool isTerminal;

    Node(char data)
    {
        this->data = data;
        this->m = vector<Node*>(26, NULL);
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

        for (char ch : word)
        {
            if (temp->m[ch - 'a'] == NULL) //insert here
            {
                Node *n = new Node(ch);
                temp->m[ch - 'a'] = n;
            }

            temp = temp->m[ch - 'a'];
        }

        temp->isTerminal = true;
    }

    bool search(string word)
    {
        Node *temp = root;
        for (char ch : word)
        {
            if (temp->m[ch - 'a'] == NULL)    return false;
            temp = temp->m[ch - 'a'];
        }

        return temp->isTerminal;
    }

    bool startsWith(string prefix)
    {
        Node *temp = root;
        for (char ch : prefix)
        {
            if (temp->m[ch - 'a'] == NULL)    return false;
            temp = temp->m[ch - 'a'];
        }

        return true;
    }
};