class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size(), n = mat[0].size();

        if (m * n != r * c)  return mat; //not possible to resize

        else
        {
            vector<vector<int>>ans(r, vector<int>(c));

            int row = 0, col = 0;

            for (int i = 0; i < r; i++)
            {
                for (int j = 0; j < c; j++)
                {
                    ans[i][j] = mat[row][col++];
                    if (col == n)
                    {
                        row++;
                        col = 0;
                    }
                    else if (row == m)   break;
                }
            }

            return ans;
        }

    }
};