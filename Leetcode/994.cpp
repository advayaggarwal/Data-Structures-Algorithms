//Mutli source BFS
//Time complexity - O(m*n)
//Space complexity - O(m*n)
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid)
    {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>>visited(m, vector<bool>(n, false));
        vector<vector<int>>dis(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>>q;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({i, j});
                    visited[i][j] = true;
                    dis[i][j] = 0;
                }
            }
        }

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        int ans = 0;

        while (!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;

            q.pop();

            for (int k = 0; k < 4; k++)
            {
                int x = i + dx[k];
                int y = j + dy[k];

                if (x >= 0 && x < m && y >= 0 && y < n && !visited[x][y] && grid[x][y] == 1)
                {
                    visited[x][y] = true;
                    grid[x][y] = 2;
                    q.push({x, y});
                    dis[x][y] = dis[i][j] + 1;
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1) return -1;

                if (grid[i][j] == 2) ans = max(ans, dis[i][j]);
            }
        }

        return ans;
    }
};