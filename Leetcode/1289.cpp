//Time complexity - O(n^3)
//Space complexity - O(n^2)
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid)
    {
        int n = grid.size();
        vector<vector<int>>dp(n + 1, vector<int>(n + 1, -1));
        return helper(n - 1, n, n, grid, dp);
    }

    int helper(int i, int n, int last, vector<vector<int>>&grid, vector<vector<int>>&dp)
    {
        if (i == 0)
        {
            int mini = INT_MAX;
            for (int col = 0; col < n; col++)
            {
                if (col != last) mini = min(mini, grid[i][col]);
            }

            return mini;
        }

        if (dp[i][last] != -1)   return dp[i][last];

        int ans = INT_MAX;
        for (int col = 0; col < n; col++)
        {
            if (last != col)
            {
                ans = min(ans, grid[i][col] + helper(i - 1, n, col, grid, dp));
            }
        }

        return dp[i][last] = ans;
    }
};


/*
Think about the most straightforward solution: find the minimum element in the first row, add it to the minimum element in the second row, and so on.

That should work, unless two minimum elements are in the same column. To account for that, let's remember the position pos of the minimum element fm.
Also, we need to remember the second minimum element sm.

For the next row, we will use fm for columns different than pos, and sm otherwise.

*/

//Time complexity - O(n^2)
//Space complexity - O(1)
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int fm = 0, sm = 0, pos = -1;

        for (int i = 0; i < n; i++)
        {
            int fm2 = INT_MAX, sm2 = INT_MAX, pos2 = -1;
            for (int j = 0; j < n; j++)
            {
                auto mn = j != pos ? fm : sm;
                if (mn + grid[i][j] < fm2)
                {
                    sm2 = fm2;
                    fm2 = mn + grid[i][j];
                    pos2 = j;
                }
                else    sm2 = min(sm2, grid[i][j] + mn);
            }
            fm = fm2;
            sm = sm2;
            pos = pos2;
        }

        return fm;
    }
};