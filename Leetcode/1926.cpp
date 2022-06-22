//BFS - Shortest Path Algorithm
//Time complexity - O(m*n)
//Space complexity- O(m*n)
class Solution {
public:
    int nearestExit(vector<vector<char>>&maze, vector<int>&entrance)
    {
        int m = maze.size(), n = maze[0].size();

        int dx[4] = {0, 0, 1, -1};
        int dy[4] = { -1, 1, 0, 0};

        queue<pair<int, int>>q;
        vector<vector<bool>>visited(m, vector<bool>(n));
        //we can avoid using visited by using maze vector as visited by marking maze[i][j] = '+', once visited
        q.push({entrance[0], entrance[1]});
        visited[entrance[0]][entrance[1]] = true;
        int steps = -1;
        while (!q.empty())
        {
            steps++;
            int sz = q.size();
            while (sz--)
            {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                if ((i == 0 or j == 0 or i == m - 1 or j == n - 1) && steps) return steps;
                //&& steps is making sure that entrance is not counted as the nearest exit point

                for (int k = 0; k < 4; k++)
                {
                    int x = i + dx[k];
                    int y = j + dy[k];

                    if (x >= 0 && x < m && y >= 0 && y < n && !visited[x][y] && maze[x][y] == '.')
                    {
                        q.push({x, y});
                        visited[x][y] = true;
                    }
                }
            }
        }

        return -1;
    }
};