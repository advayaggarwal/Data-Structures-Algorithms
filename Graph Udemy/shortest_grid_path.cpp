#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

int dx[4] = {0, 0, 1, -1};
int dy[4] = { -1, 1, 0, 0};

int shortest_path(vector<vector<int>>grid)
{
    int m = grid.size(), n = grid[0].size();
    set<pair<int, pii>>s; //{dis, {i,j}}
    vector<vector<int>>dist(m, vector<int>(n, INT_MAX));
    dist[0][0] = grid[0][0];
    s.insert({dist[0][0], {0, 0}});

    while (!s.empty())
    {
        auto node = *s.begin();
        s.erase(s.begin());

        int curr_dist = node.first;
        int i = node.second.first;
        int j = node.second.second;

        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k];
            int y = j + dy[k];

            if (x < 0 or x >= m or y<0 or y >= n)   continue;
            if (curr_dist + grid[x][y] < dist[x][y])
            {
                s.erase({dist[x][y], {x, y}});
                dist[x][y] = curr_dist + grid[x][y];
                s.insert({dist[x][y], {x, y}});
            }
        }
    }

    return dist[m - 1][n - 1];
}