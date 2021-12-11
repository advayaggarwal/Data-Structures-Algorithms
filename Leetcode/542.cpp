//BFS - Shortest path algorithm
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>>distance(m, vector<int>(n, INT_MAX));

        queue<pair<int, int>>q;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 0)
                {
                    q.push({i, j});
                    distance[i][j] = 0;
                }
            }
        }

        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        while (!q.empty())
        {
            int sr = q.front().first;
            int sc = q.front().second;

            q.pop();

            for (int k = 0; k < 4; k++)
            {
                int x = sr + dx[k];
                int y = sc + dy[k];

                if (x >= 0 && x < m && y >= 0 && y < n && mat[x][y])
                {
                    if (distance[x][y] > distance[sr][sc] + 1)
                    {
                        distance[x][y] = distance[sr][sc] + 1;
                        q.push({x, y});
                    }
                }
            }
        }

        return distance;
    }
};