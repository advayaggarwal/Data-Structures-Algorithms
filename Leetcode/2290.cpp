//Dijkstra's Algorithm - Obstacle edge having weight 1 and normal edge having weight 0, then finding shortest path
//Time complexity - O(m*n*log(m*n))
//Space complexity - O(m*n)
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid)
    {
        int m = grid.size(), n = grid[0].size();
        int dx[4] = { -1, 1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        set<pair<int, pair<int, int>>>q; //{obstacles removed till here, {x,y}};
        q.insert({0, {0, 0}});
        vector<vector<int>>dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = 0;

        while (!q.empty())
        {
            auto it = q.begin();
            int i = it->second.first, j = it->second.second, ob = it->first;
            q.erase(it);
            if (i == m - 1 && j == n - 1)   return ob;

            for (int k = 0; k < 4; k++)
            {
                int x = i + dx[k];
                int y = j + dy[k];

                if (x >= 0 && x < m && y >= 0 && y < n && dist[x][y] > dist[i][j] + grid[x][y])
                {
                    dist[x][y] = dist[i][j] + grid[x][y];
                    q.insert({dist[x][y], {x, y}});
                }
            }
        }

        return -1;
    }
};

//0-1 BFS
//Time complexity - O(m*n)
//Space complexity - O(m*n)
class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid)
    {
        int m = grid.size(), n = grid[0].size();
        int dx[4] = { -1, 1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        deque<pair<int, int>>q; //{x,y};
        q.push_back({0, 0});
        vector<vector<int>>dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = 0;

        while (!q.empty())
        {
            auto it = q.front();
            int i = it.first, j = it.second;
            q.pop_front();
            if (i == m - 1 && j == n - 1)   return dist[i][j];

            for (int k = 0; k < 4; k++)
            {
                int x = i + dx[k];
                int y = j + dy[k];

                if (x >= 0 && x < m && y >= 0 && y < n && dist[x][y] > dist[i][j] + grid[x][y])
                {
                    dist[x][y] = dist[i][j] + grid[x][y];
                    if (grid[x][y] == 0) q.push_front({x, y});
                    else q.push_back({x, y});
                }
            }
        }

        return -1;
    }
};