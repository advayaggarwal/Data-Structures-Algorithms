//Time complexity - O(n)
//Space complexity - O(26)
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        //Sliding window of size k
        int k = p.size();

        vector<int>res;

        unordered_map<char, int>m; //char and its freq
        for (char ch : p)    m[ch]++;
        int i = 0, j = 0;
        while (j < s.size())
        {
            m[s[j]]--;

            if (j - i + 1 < k) j++;

            else //got the window of size k
            {
                if (allZero(m))    res.push_back(i);
                m[s[i]]++;
                i++;
                j++;
            }
        }

        return res;
    }

    bool allZero(unordered_map<char, int>&m)
    {
        for (auto p : m)
        {
            if (p.second != 0) return false;
        }
        return true;
    }
};