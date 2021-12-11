//Time complexity - O(n^2)
//Space complexity - O(n^2), considering res vector
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        for (int i = 0; i < numRows; i++)
        {
            res[i].resize(i + 1);
            for (int j = 0; j <= i; j++)
            {
                if (j == 0 or i == j)    res[i][j] = 1;
                else  res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
            }
        }

        return res;
    }
};