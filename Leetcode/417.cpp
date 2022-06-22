/*
    Idea -  Apply BFS or DFS as per the rules from both atlantic and pacific oceans(boundary cells),
    and store the visited cells in the vector, result will be the cells that are visited by both the oceans.
*/

//Time complexity - O(m*n)
//Space complexity - O(m*n)
class Solution {
public:
    int dx[4] = { -1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights)
    {
        int m = heights.size(), n = heights[0].size();

        vector<vector<bool>> atlantic(m, vector<bool>(n)), pacific(m, vector<bool>(n));

        for (int i = 0; i < m; i++)
        {
            dfs(i, 0, m, n, heights, pacific);
            dfs(i, n - 1, m, n, heights, atlantic);
        }

        for (int j = 0; j < n; j++)
        {
            dfs(0, j, m, n, heights, pacific);
            dfs(m - 1, j, m, n, heights, atlantic);
        }

        vector<vector<int>>res;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (pacific[i][j] && atlantic[i][j])  res.push_back({i, j});
            }
        }

        return res;
    }

    void dfs(int i, int j, int m, int n, vector<vector<int>>&heights, vector<vector<bool>>&visited)
    {
        visited[i][j] = true;

        for (int k = 0; k < 4; k++)
        {
            int x = dx[k] + i;
            int y = dy[k] + j;

            if (x >= 0 && x < m && y >= 0 && y < n && !visited[x][y] && heights[x][y] >= heights[i][j])    dfs(x, y, m, n, heights, visited);
        }
    }
};