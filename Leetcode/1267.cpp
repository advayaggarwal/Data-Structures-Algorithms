//Time complexity - O(m*n)
//Space complexity - O(m+n)
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> rowCount(m, 0), colCount(n, 0);

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    rowCount[i]++;
                    colCount[j]++;
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j])
                {
                    if (rowCount[i] > 1 or colCount[j] > 1)    ans += 1;
                }
            }
        }
        return ans;
    }
};