//The catch over here is that the same element can be pushed into the queue multiple times if we can reach there
//by destroying less obstacles
//Time complexity - O(m*n*k)
//Space complexity - O(m*n*k)
class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>>obs(m, vector<int>(n, -1)); //can also be used as visited
        queue<vector<int>>q; //{i, j, max remaining obstacles that we can destroy}
        q.push({0, 0, k});
        obs[0][0] = k;
        vector<pair<int, int>>dir = {{0, 1}, {0, -1}, {1, 0}, { -1, 0}};
        int steps = 0;
        while (!q.empty())
        {
            int sz = q.size();
            while (sz--)
            {
                vector<int>temp = q.front();
                q.pop();
                int i =  temp[0], j = temp[1], ob = temp[2];

                if (i == m - 1 && j == n - 1)    return steps;
                for (int d = 0; d < 4; d++)
                {
                    int x = i + dir[d].first;
                    int y = j + dir[d].second;

                    if (x < 0 or x >= m or y<0 or y >= n)   continue;

                    int currObs = ob - grid[x][y]; //current remaining
                    if (obs[x][y] == -1 && currObs >= 0) //not visited
                    {
                        obs[x][y] = currObs;
                        q.push({x, y, currObs});
                    }

                    else if (obs[x][y] < currObs && currObs >= 0) //visited but we came here again but by destroying less obstacles
                    {
                        obs[x][y] = currObs;
                        q.push({x, y, currObs});
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};