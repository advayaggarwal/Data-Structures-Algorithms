//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    vector<int> partitionLabels(string s)
    {
        vector<int>res;
        vector<int>last(26, 0);
        int n = s.size();

        for (int i = 0; i < n; i++) last[s[i] - 'a'] = i;

        int start = 0, end = 0;
        for (int i = 0; i < n; i++)
        {
            end = max(end, last[s[i] - 'a']);
            if (i == end)
            {
                res.push_back(i - start + 1);
                start = i + 1;
            }
        }

        return res;
    }
};