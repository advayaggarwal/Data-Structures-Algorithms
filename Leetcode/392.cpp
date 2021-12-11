//Time complexity - O(t.size())
//Space complexity - O(1)
class Solution {
public:
    bool isSubsequence(string s, string t) {

        int n = s.size(), m = t.size();
        int i = 0, j = 0;
        while (i != n && j != m)
        {
            if (s[i] == t[j])   i++;
            j++;
        }

        return (i == n);
    }
};


//Follow Up
//Same as above, just we've stored the result in a map for the strings for which we know the ans of isSubsequence
//as in the test cases words are repeated, though not a good solution
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {

        unordered_map<string, bool>m;
        int count = 0;
        for (string st : words)
        {
            if (m.find(st) != m.end())
            {
                if (m[st] == true) count++;
            }
            else
            {
                if (isSubsequence(st, s))
                {
                    m[st] = true;
                    count++;
                }
                else m[st] = false;
            }
        }

        return count;
    }

    bool isSubsequence(string st, string s)
    {
        int i = 0;

        for (int j = 0; j < (int)s.size(); j++)
        {
            if (st[i] == s[j]) i++;

            if (i >= st.size())    return true;
        }

        return false;
    }

};

//3rd approach
//Time complexity - O(n^2), n = s.size()
//Space complexity - O(n^2)
//Find LCS of both the strings
//return lcs == s.size()