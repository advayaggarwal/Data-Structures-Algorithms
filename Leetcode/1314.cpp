//Using 2D prefix sum
//Time complexity - O(n^2)
//Space complexity - O(n^2)
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k)
    {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>>prefix(m + 1, vector<int>(n + 1, 0)); // prefix[i][j] is sum of all elements from rectangle (0,0,i,j) as left, top, right, bottom corresponding

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                prefix[i][j] = mat[i - 1][j - 1] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
            }
        }

        vector<vector<int>>ans(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int r1 = max(0, i - k), r2 = min(i + k, m - 1);
                int c1 = max(0, j - k), c2 = min(j + k, n - 1);
                r1++; r2++; c1++; c2++; // Since `prefix` start with 1 so we need to increase r1, c1, r2, c2 by 1

                ans[i][j] = prefix[r2][c2] - prefix[r2][c1 - 1] - prefix[r1 - 1][c2] + prefix[r1 - 1][c1 - 1];
            }
        }

        return ans;
    }
};