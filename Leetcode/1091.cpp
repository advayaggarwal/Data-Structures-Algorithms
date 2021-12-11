class Solution {
public:

    int shortestPathBinaryMatrix(vector<vector<int>>& grid)
    {
        if (grid[0][0] == 1) return -1;
        int n = grid.size();
        vector<vector<bool>>visited(n, vector<bool>(n, false));

        int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
        int dy[8] = { -1, 1, 0, 0, 1, 1, -1, -1};

        queue<pair<int, int>>q;
        q.push({0, 0});
        visited[0][0] = true;
        vector<vector<int>>dis(n, vector<int>(n, -1));
        dis[0][0] = 1;
        while (!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            if (i == n - 1 && j == n - 1)    break;

            for (int k = 0; k < 8; k++)
            {
                int x = i + dx[k];
                int y = j + dy[k];

                if (x >= 0 && x < n && y >= 0 && y < n && !visited[x][y] && grid[x][y] == 0)
                {
                    dis[x][y] = dis[i][j] + 1;
                    visited[x][y] = true;
                    q.push({x, y});
                }
            }
        }

        return dis[n - 1][n - 1];
    }
};