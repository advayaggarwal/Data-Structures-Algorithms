//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        unordered_map<string, int>m;
        vector<string>res;
        int n = s.size();

        if (n < 10)   return res;

        for (int i = 0; i < n - 9; i++) //there will be n-9 substrings of length 10 of a string of length n i.e. n-10+1
        {
            string str = s.substr(i, 10);
            m[str]++;
        }

        for (auto p : m)
        {
            if (p.second > 1)    res.push_back(p.first);
        }

        return res;
    }
};