//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    string reverseWords(string s)
    {
        stringstream iss(s);
        string word, res;
        vector<string>words;

        while (iss >> word)  words.push_back(word);

        for (int i = words.size() - 1; i >= 0; i--)    res += words[i] + " ";
        res.pop_back();

        return res;
    }
};