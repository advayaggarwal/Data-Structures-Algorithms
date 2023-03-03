//Time Complexity - O(S), where S is the sum of the lengths of words in words
//Space Complexity: O(S)
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words)
    {
        vector<string>encode = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

        unordered_set<string>s;

        for (string word : words)
        {
            string t;
            for (char c : word)
            {
                t += encode[c - 'a'];
            }

            s.insert(t);
        }

        return s.size();
    }
};