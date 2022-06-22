//Time complexity - O(n^n)
//Space complexity - O(n^2)
class Solution {
public:
    int totalNQueens(int n)
    {
        string temp = string(n, '.');
        vector<string>grid(n, temp);
        return helper(0, n, grid);
    }

    int helper(int i, int n, vector<string>&grid)
    {
        if (i == n)  return 1;

        int count = 0;

        for (int j = 0; j < n; j++)
        {
            if (isSafe(i, j, grid))
            {
                grid[i][j] = 'Q';
                count += helper(i + 1, n, grid);
                grid[i][j] = '.';
            }
        }

        return count;
    }

    bool isSafe(int r, int c, vector<string>&grid)
    {
        //checking c column
        for (int i = 0; i <= r; i++)
        {
            if (grid[i][c] == 'Q')   return false;
        }

        //upper diagonal on left
        for (int i = r, j = c; i >= 0 && j >= 0; i--, j--)
        {
            if (grid[i][j] == 'Q')   return false;
        }

        //upper diagonal on right
        for (int i = r, j = c; i >= 0 && j < grid.size(); i--, j++)
        {
            if (grid[i][j] == 'Q')   return false;
        }

        return true;
    }
};