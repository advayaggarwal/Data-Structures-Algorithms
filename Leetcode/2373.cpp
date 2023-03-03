//Time complexity - O(9*n^2)
//Space complexity - O(1)
class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid)
    {
        int n = grid.size();
        vector<vector<int>>res(n - 2, vector<int>(n - 2));

        for (int i = 0; i <= n - 3; i++)
        {
            for (int j = 0; j <= n - 3; j++)
            {
                int val = 0;
                for (int k = i; k < i + 3; k++)
                {
                    for (int l = j; l < j + 3; l++)
                    {
                        val = max(val, grid[k][l]);
                    }
                }

                res[i][j] = val;
            }
        }

        return res;
    }
};