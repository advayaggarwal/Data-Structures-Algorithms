//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    string convert(string s, int numRows)
    {
        vector<string>vs(numRows);

        int n = s.size(), i = 0;
        while (i < n)
        {
            for (int j = 0; j < numRows && i < n; j++)    vs[j].push_back(s[i++]); // vertically down
            for (int j = numRows - 2; j >= 1 && i < n; j--) vs[j].push_back(s[i++]); // obliquely up
        }

        string zigzag;
        for (string st : vs) zigzag += st;
        return zigzag;
    }
};