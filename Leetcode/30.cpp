//Time complexity - O(n*m*k), where k is s.size(), n = words[0].size() and m is number of words
//Space complexity - O(m)
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words)
    {
        unordered_map<string, int>freq;
        int n = words[0].size(), m = words.size();

        for (auto word : words)  freq[word]++;

        vector<int>res;

        for (int i = 0; i + n * m <= s.size(); i++)
        {
            unordered_map<string, int>temp;
            int j;
            for (j = 0; j < m; j++)
            {
                string t = s.substr(i + j * n, n);
                if (!freq.count(t))  break;
                temp[t]++;
                if (temp[t] > freq[t])   break;
            }

            if (j == m) res.push_back(i);
        }

        return res;
    }
};