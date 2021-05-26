class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        res[0].push_back(1);
        for (int i = 1; i < numRows; i++)
        {
            res[i].resize(i + 1);
            for (int j = 0; j <= i; j++)
            {
                if (i == j)    res[i][j] = 1;
                else if (j == 0)   res[i][j] = 1;
                else  res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
            }
        }
        return res;
    }
};