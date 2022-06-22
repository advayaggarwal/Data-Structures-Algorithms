//Time complexity - O(n*l*l), where l is max word size
//Space complexity - O(n*l)
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words)
    {
        unordered_set<string>good(words.begin(), words.end());

        for (string word : words)
        {
            for (int i = 1; i < word.size(); i++)    good.erase(word.substr(i));
        }

        int ans = 0;
        for (string s : good)    ans += s.size() + 1;

        return ans;
    }
};

//Using Trie
//Time complexity - O(n*l), where l is max word size
//Space complexity - O(n*l)
class TrieNode {
public:
    unordered_map<char, TrieNode*>children;
};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words)
    {
        unordered_set<string>uniqueWords(words.begin(), words.end());
        vector<pair<TrieNode*, int>>leaves; //for pushing all the ending nodes of the words along with their depth
        TrieNode *root = new TrieNode;

        for (string word : uniqueWords)
        {
            TrieNode *curr = root;
            for (int i = word.size() - 1; i >= 0; i--)
            {
                if (!curr->children.count(word[i]))   curr->children[word[i]] = new TrieNode;
                curr = curr->children[word[i]];
            }

            leaves.push_back({curr, word.size() + 1});
        }

        int ans = 0;
        for (int i = 0; i < leaves.size(); i++)
        {
            if (leaves[i].first->children.size() == 0) //means a leaf node, as it has no child
            {
                ans += leaves[i].second;
            }
        }

        return ans;
    }
};