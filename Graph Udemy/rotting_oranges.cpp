#include<bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>>grid)
{
	int m = grid.size();
	int n = grid[0].size();

	int fresh = 0;

	queue<pair<int, int>>q;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (grid[i][j] == 2)
			{
				q.push({i, j});
			}

			else if (grid[i][j] == 1)	fresh++;
		}
	}

	int ans = -1;

	int dx[4] = {1, -1, 0, 0};
	int dy[4] = {0, 0, 1, -1};

	while (!q.empty())
	{
		int sz = q.size();
		while (sz--)
		{
			int i = q.front().first;
			int j = q.front().second;
			q.pop();

			for (int k = 0; k < 4; k++)
			{
				int x = i + dx[k];
				int y = j + dy[k];

				if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1)
				{
					grid[x][y] = 2;
					fresh--;
					q.push({x, y});
				}
			}
		}

		ans++;
	}

	if (fresh > 0)	return -1;
	if (ans == -1)	return 0;

	return ans;
}