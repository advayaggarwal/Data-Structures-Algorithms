//Using DFS
//Time complexity - O(m*n)
//Space complexity - O(m*n)
class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {

        int oldColor = image[sr][sc];
        int m = image.size(), n = image[0].size();
        vector<vector<bool>>visited(m, vector<bool>(n, false));

        dfs(sr, sc, m, n, image, oldColor, newColor, visited);
        return image;
    }

    void dfs(int i, int j, int m, int n, vector<vector<int>>&image, int oldColor, int newColor, vector<vector<bool>>&visited)
    {
        image[i][j] = newColor;
        visited[i][j] = true;

        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k];
            int y = j + dy[k];

            if (x >= 0 && x < m && y >= 0 && y < n && !visited[x][y] && image[x][y] == oldColor)
            {
                dfs(x, y, m, n, image, oldColor, newColor, visited);
            }

        }
    }
};

//Using BFS
//Time complexity - O(m*n)
//Space complexity - O(m*n)
class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {

        bfs(sr, sc, image, newColor);
        return image;
    }

    void bfs(int sr, int sc, vector<vector<int>>&image, int newColor)
    {
        int oldColor = image[sr][sc];
        int m = image.size(), n = image[0].size();
        vector<vector<bool>>visited(m, vector<bool>(n, false));

        queue<pair<int, int>>q;
        q.push({sr, sc});
        visited[sr][sc] = true;
        image[sr][sc] = newColor;

        while (!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++)
            {
                int x = i + dx[k];
                int y = j + dy[k];

                if (x >= 0 && x < m && y >= 0 && y < n && !visited[x][y] && image[x][y] == oldColor)
                {
                    image[x][y] = newColor;
                    visited[x][y] = true;
                    q.push({x, y});
                }
            }
        }
    }
};