class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int>m;
        for (char c : t)   m[c]++;
        int count = m.size();
        int n = s.size();
        int i = 0, j = 0;
        int start = 0, end = -1;
        int mn = INT_MAX;
        while (j < n)
        {
            if (m.find(s[j]) != m.end()) //s[j] is there in the map
            {
                m[s[j]]--;
                if (m[s[j]] == 0)  count--;
            }

            while (count == 0) //candidate for the answer
            {
                if (mn > j - i + 1) //picking the minimum window
                {
                    mn = j - i + 1;
                    start = i;
                    end = j;
                }

                if (m.find(s[i]) != m.end())
                {
                    m[s[i]]++;
                    if (m[s[i]] == 1)  count++;
                }
                i++;
            }
            j++;
        }

        string res;
        for (int i = start; i <= end; i++)   res += s[i];
        return res;

    }
};