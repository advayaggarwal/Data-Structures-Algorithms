//Time complexity - O(m*n), where m is the size of vector and n is the size of smallest string
//Space complexity - O(1)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        int n = strs.size();
        if (n == 0)  return "";
        string res;

        int index = 0;

        for (char c : strs[0])
        {
            for (int i = 1; i < n; i++)
            {
                if (index >= strs[i].size() or strs[i][index] != c)    return res;
            }
            res += c;
            index++;
        }

        return res;
    }
};