//Mutli source BFS
//Time complexity - O(m*n)
//Space complexity - O(m*n)
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid)
    {
        int m = grid.size(), n = grid[0].size();
        int fresh = 0;
        queue<pair<int, int>>q;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)    q.push({i, j});
                else if (grid[i][j] == 1)    fresh++;
            }
        }

        if (!fresh)   return 0;

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        int level = -1;

        while (!q.empty())
        {
            level++;
            int sz = q.size();

            while (sz--)
            {
                int i = q.front().first;
                int j = q.front().second;

                q.pop();

                for (int k = 0; k < 4; k++)
                {
                    int x = i + dx[k];
                    int y = j + dy[k];

                    if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1)
                    {
                        grid[x][y] = 2;
                        fresh--;
                        q.push({x, y});
                    }
                }
            }
        }

        return fresh ? -1 : level;
    }
};