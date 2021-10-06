//Recursion - TLE
//Time complexity - O(4^n)
class Solution {
public:
    bool isScramble(string s1, string s2) {

        if (s1.size() != s2.size())  return false;

        if (s1 == s2)    return true;

        return scramble(s1, s2);
    }

    bool scramble(string s1, string s2)
    {
        if (s1 == s2)   return true;

        if (s1.size() <= 1) return false;

        int n = s1.size();

        for (int i = 1; i < n; i++)
        {
            bool op1 = (scramble(s1.substr(0, i), s2.substr(0, i)) && scramble(s1.substr(i, n - i), s2.substr(i, n - i)));
            if (op1) return true;
            bool op2 = (scramble(s1.substr(0, i), s2.substr(n - i, i)) && scramble(s1.substr(i, n - i), s2.substr(0, n - i)));
            if (op2)    return true;
        }

        return false;
    }
};

//Top Down DP
//Time complexity - O(n^3)
class Solution {
public:
    bool isScramble(string s1, string s2) {

        if (s1.size() != s2.size())  return false;

        if (s1 == s2)    return true;

        unordered_map<string, bool>m;
        return scramble(s1, s2, m);
    }

    bool scramble(string s1, string s2, unordered_map<string, bool>&m)
    {
        if (s1 == s2)   return true;

        if (s1.size() <= 1) return false;

        string temp = s1 + " " + s2;
        if (m.find(temp) != m.end())    return m[temp];
        int n = s1.size();

        for (int i = 1; i < n; i++)
        {
            bool op1 = (scramble(s1.substr(0, i), s2.substr(0, i), m) && scramble(s1.substr(i, n - i), s2.substr(i, n - i), m));
            if (op1) return m[temp] = true;
            bool op2 = (scramble(s1.substr(0, i), s2.substr(n - i, i), m) && scramble(s1.substr(i, n - i), s2.substr(0, n - i), m));
            if (op2)    return m[temp] = true;
        }

        return m[temp] = false;
    }

};