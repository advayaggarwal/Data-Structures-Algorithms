//Using 2D prefix sum
//Time complexity - O(n^2)
//Space complexity - O(n^2)
class NumMatrix {
public:
    vector<vector<int>>prefix;
    NumMatrix(vector<vector<int>>& matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        prefix = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                prefix[i][j] = matrix[i - 1][j - 1] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int r1, int c1, int r2, int c2) //O(1)
    {
        r1++; c1++; r2++; c2++;
        int ans = prefix[r2][c2] - prefix[r2][c1 - 1] - prefix[r1 - 1][c2] + prefix[r1 - 1][c1 - 1];
        return ans;
    }
};