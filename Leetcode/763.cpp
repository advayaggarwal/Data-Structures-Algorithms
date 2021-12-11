//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    vector<int> partitionLabels(string s)
    {
        vector<int>res;
        vector<int>last(26, 0);
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            last[s[i] - 'a'] = i;
        }

        int j = 0, anchor = 0;

        for (int i = 0; i < n; i++)
        {
            j = max(j, last[s[i] - 'a']);

            if (i == j)
            {
                res.push_back(i - anchor + 1);
                anchor = i + 1;
            }
        }

        return res;
    }
};