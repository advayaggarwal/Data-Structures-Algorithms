//Recursion + Backtracking
//Time complexity - O(3^N), where N is number of cells in the matrix
//Space complexity - O(N)
class Solution {
public:
    int dx[4] = { -1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int uniquePathsIII(vector<vector<int>>& grid)
    {
        int m = grid.size(), n = grid[0].size();
        int startX, startY, totalZeroes = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    startX = i;
                    startY = j;
                }

                else if (grid[i][j] == 0)    totalZeroes++;
            }
        }

        return dfs(startX, startY, totalZeroes, grid);
    }

    int dfs(int i, int j, int &totalZeroes, vector<vector<int>>&grid)
    {
        if (grid[i][j] == 2)
        {
            return totalZeroes == -1 ? 1 : 0;
            //why -1 because we are covering one extra cell than the zero count, if that's the case we find the
            //path and return 1 otherwise 0
        }

        grid[i][j] = -1; //marking visited as -1
        totalZeroes--;
        int ans = 0; //total ways

        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k];
            int y = j + dy[k];
            if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] != -1)
            {
                ans += dfs(x, y, totalZeroes, grid);
            }
        }

        //Backtracking
        totalZeroes++;
        grid[i][j] = 0; //marking not visited

        return ans;
    }
};