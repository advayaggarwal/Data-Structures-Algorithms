//Multisource BFS
//Time complexity - O(m*n)
//Space complexity - O(m*n)
class Solution {
public:
    int dx[4] = { -1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int maxDistance(vector<vector<int>>&grid)
    {
        int n = grid.size();

        int level = 0;
        queue<pair<int, int>>q;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1) q.push({i, j});
            }
        }

        if (q.size() == 0 or q.size() == n * n)   return -1; //No land or no water

        while (!q.empty())
        {
            level++;
            int sz = q.size();
            while (sz--)
            {
                auto p = q.front();
                q.pop();
                for (int k = 0; k < 4; k++)
                {
                    int x = p.first + dx[k];
                    int y = p.second + dy[k];
                    if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 0)
                    {
                        grid[x][y] = 1;
                        q.push({x, y});
                    }
                }
            }
        }

        return level - 1;
    }
};