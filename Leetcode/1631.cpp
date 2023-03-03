//DFS with Binary Search
//Time complexity - O(m*n*log(INT_MAX))
//Space complexity - O(m*n)
class Solution {
public:
    int dx[4] = { -1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int minimumEffortPath(vector<vector<int>>& heights)
    {
        int start = 0, end = INT_MAX, ans = INT_MAX;
        int m = heights.size(), n = heights[0].size();

        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            vector<vector<bool>>visited(m, vector<bool>(n, false));
            if (dfs(0, 0, mid, m, n, heights, visited))
            {
                ans = mid;
                end = mid - 1;
            }

            else start = mid + 1;
        }

        return ans;
    }

    bool dfs(int i, int j, int mid, int m, int n, vector<vector<int>>&heights, vector<vector<bool>>&visited)
    {
        if (i == m - 1 && j == n - 1)    return true;
        visited[i][j] = true;

        bool possible = false;

        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k];
            int y = j + dy[k];

            if (x >= 0 && x < m && y >= 0 && y < n && !visited[x][y] && (abs(heights[x][y] - heights[i][j]) <= mid))
            {
                possible |= dfs(x, y, mid, m, n, heights, visited);
            }
        }

        return possible;
    }
};

//Dijkstra's Algorithm
//Time complexity - O(m*n*log(m*n))
//Space complexity - O(m*n)
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights)
    {
        int m = heights.size(), n = heights[0].size();
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        set<pair<int, pair<int, int>>>s; //{dist, {x, y}};
        vector<vector<int>>dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = 0;
        s.insert({0, {0, 0}});

        while (!s.empty())
        {
            auto it = *(s.begin());
            int diff = it.first;
            int i = it.second.first, j = it.second.second;
            if (i == m - 1 && j == n - 1)    return diff; //for small improvement
            s.erase(it);

            for (int k = 0; k < 4; k++)
            {
                int x = i + dx[k], y = j + dy[k];

                if (x >= 0 && x < m && y >= 0 && y < n && max(diff, abs(heights[i][j] - heights[x][y])) < dist[x][y])
                {
                    if (s.count({dist[x][y], {x, y}}))   s.erase({dist[x][y], {x, y}});
                    dist[x][y] = max(diff, abs(heights[i][j] - heights[x][y]));
                    s.insert({dist[x][y], {x, y}});
                }
            }
        }

        return dist[m - 1][n - 1];
    }
};

//Dijkstra's Algorithm
//Time complexity - O(m*n*log(m*n))
//Space complexity - O(m*n)
class Solution {
public:
    int minimumEffortPath(vector<vector<int>> &heights) {
        int m = heights.size(), n = heights[0].size();
        int dirs[5] = { -1, 0, 1, 0, -1};

        std::vector<vector<int>> efforts(m, vector<int>(n, INT_MAX));
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.emplace(0, 0); // First item is effort, second is row * 100 + col
        while (!pq.empty()) {
            int effort = pq.top().first;
            int x = pq.top().second / 100, y = pq.top().second % 100;
            pq.pop();

            if (x == m - 1 && y == n - 1) return effort;
            if (effort >= efforts[x][y]) continue;
            efforts[x][y] = effort;

            for (int i = 0; i < 4; i++) {
                int nx = x + dirs[i], ny = y + dirs[i + 1];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                int n_effort = max(effort, abs(heights[x][y] - heights[nx][ny]));
                pq.emplace(n_effort, nx * 100 + ny);
            }
        }
        return -1;
    }
};