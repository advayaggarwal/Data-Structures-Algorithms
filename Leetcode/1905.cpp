//Time complexity - O(m*n)
//Space complexity - O(m*n)
class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = { -1, 1, 0, 0};
    int countSubIslands(vector<vector<int>>&grid1, vector<vector<int>>&grid2)
    {
        int m = grid1.size(), n = grid1[0].size();
        //Removing all the non-common sub-islands
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid2[i][j] == 1 && grid1[i][j] == 0)  dfs(i, j, m, n, grid2);
            }
        }

        int ans = 0;
        //Counting sub-islands
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid2[i][j] == 1)
                {
                    ans++;
                    dfs(i, j, m, n, grid2);
                }
            }
        }

        return ans;
    }

    void dfs(int i, int j, int m, int n, vector<vector<int>>&grid)
    {
        grid[i][j] = 0;

        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k];
            int y = j + dy[k];

            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1)    dfs(x, y, m, n, grid);
        }
    }
};

//Shorter code
//Time complexity - O(m*n)
//Space complexity - O(m*n)
class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = { -1, 1, 0, 0};
    int countSubIslands(vector<vector<int>>&grid1, vector<vector<int>>&grid2)
    {
        int m = grid1.size(), n = grid1[0].size();

        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid2[i][j] == 1)
                {
                    bool res = true;
                    dfs(i, j, m, n, grid1, grid2, res);
                    ans += res;
                }
            }
        }

        return ans;
    }

    void dfs(int i, int j, int m, int n, vector<vector<int>>&grid1, vector<vector<int>>&grid2, bool &res)
    {
        if (grid2[i][j] == 1 && grid1[i][j] == 0)    res = false;
        grid2[i][j] = 0;

        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k];
            int y = j + dy[k];

            if (x >= 0 && x < m && y >= 0 && y < n && grid2[x][y] == 1)    dfs(x, y, m, n, grid1, grid2, res);
        }
    }
};