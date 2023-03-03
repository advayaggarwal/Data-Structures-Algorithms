//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2)
    {
        string s1, s2;
        for (string s : word1)   s1 += s;
        for (string s : word2)   s2 += s;
        return s1 == s2;
    }
};

//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2)
    {
        int p1 = 0, p2 = 0, w1 = 0, w2 = 0;
        while (w1 < word1.size() && w2 < word2.size())
        {
            string s1 = word1[w1], s2 = word2[w2];

            if (s1[p1] != s2[p2])    return false;

            if (p1 == s1.size() - 1)
            {
                p1 = 0;
                w1++;
            }

            else p1++;

            if (p2 == s2.size() - 1)
            {
                p2 = 0;
                w2++;
            }

            else p2++;
        }

        return w1 == word1.size() && w2 == word2.size();
    }
};