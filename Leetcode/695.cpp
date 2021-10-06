//DFS
//Time complexity - O(m*n)
//Space complexity - O(m*n)
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int m = grid.size(), n = grid[0].size();
        int ans = 0;

        vector<vector<bool>>visited(m, vector<bool>(n, false));

        int dx[] = { -1, 1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visited[i][j] && grid[i][j] == 1)
                {
                    int area = 0;
                    dfs(i, j, m, n, grid, visited, area, dx, dy);
                    ans = max(ans, area);
                }
            }
        }

        return ans;
    }

    void dfs(int i, int j, int m, int n, vector<vector<int>>& grid, vector<vector<bool>>&visited, int &area, int dx[], int dy[])
    {
        visited[i][j] = true;
        area++;

        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k];
            int y = j + dy[k];

            if (x >= 0 and y >= 0 and x < m and y < n and !visited[x][y] and grid[x][y] == 1)
            {
                dfs(x, y, m, n, grid, visited, area, dx, dy);
            }
        }


    }
};

//BFS
//Time complexity - O(m*n)
//Space complexity - O(m*n)
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int m = grid.size(), n = grid[0].size();
        int ans = 0;

        vector<vector<bool>>visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visited[i][j] && grid[i][j] == 1)
                {
                    int area = 0;
                    bfs(i, j, m, n, grid, visited, area);
                    ans = max(ans, area);
                }
            }
        }

        return ans;
    }

    void bfs(int i, int j, int m, int n, vector<vector<int>>& grid, vector<vector<bool>>&visited, int &area)
    {
        int dx[] = { -1, 1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        queue<pair<int, int>>q;
        q.push({i, j});
        visited[i][j] = true;

        while (!q.empty())
        {
            pair<int, int> p  = q.front();
            q.pop();
            int a = p.first;
            int b = p.second;
            area++;
            for (int k = 0; k < 4; k++)
            {
                int x = a + dx[k];
                int y = b + dy[k];

                if (x >= 0 and y >= 0 and x < m and y < n and !visited[x][y] and grid[x][y] == 1)
                {
                    q.push({x, y});
                    visited[x][y] = true;
                }
            }
        }
    }