//Time complexity - O(26*n^2)
//Space complexity - O(26*n)
class Solution {
public:
    int maxProduct(vector<string>& words)
    {
        int n = words.size();
        vector<vector<bool>>freq(n, vector<bool>(26, false));

        for (int i = 0; i < n; i++)
        {
            for (char c : words[i])  freq[i][c - 'a'] = true;
        }

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (possible(i, j, freq))
                {
                    int sz = words[i].size() * words[j].size();
                    ans = max(ans, sz);
                }
            }
        }

        return ans;
    }

    bool possible(int i, int j, vector<vector<bool>>&freq)
    {
        for (int k = 0; k < 26; k++)
        {
            if (freq[i][k] && freq[j][k])    return false;
        }

        return true;
    }
};

//Using Bitmasking
//Time complexity - O(n^2)
//Space complexity - O(n)
class Solution {
public:
    int maxProduct(vector<string>& words)
    {
        int n = words.size();
        vector<int>mask(n);

        for (int i = 0; i < n; i++)
        {
            for (char c : words[i])  mask[i] |= 1 << (c - 'a');
        }

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if ((mask[i] & mask[j]) == 0) //possible because no bits will match
                {
                    int sz = words[i].size() * words[j].size();
                    ans = max(ans, sz);
                }
            }
        }

        return ans;
    }
};