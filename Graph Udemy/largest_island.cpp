#include<bits/stdc++.h>
using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool isSafe(int x, int y, vector<vector<bool>>&visited, vector<vector<int>> &grid)
{
	int m = grid.size(), n = grid[0].size();

	return (x >= 0 && x < m && y >= 0 && y < n && !visited[x][y] && grid[x][y] == 1);
}

void dfs(int i, int j, vector<vector<bool>>&visited, vector<vector<int>> &grid, int &area)
{
	visited[i][j] = true;
	area++;

	for (int k = 0; k < 4; k++) //visiting all the neighbours
	{
		int x = i + dx[k];
		int y = j + dy[k];

		if (isSafe(x, y, visited, grid))	dfs(x, y, visited, grid, area);
	}
}


void bfs(int i, int j, vector<vector<bool>>&visited, vector<vector<int>>&grid, int &area)
{
	area++;
	queue<pair<int, int>>q;
	q.push({i, j});
	visited[i][j] = true;

	while (!q.empty())
	{
		pair<int, int>p = q.front();
		q.pop();

		for (int k = 0; k < 4; k++)
		{
			int x = p.first + dx[k];
			int y = p.second + dy[k];

			if (isSafe(x, y, visited, grid))
			{
				q.push({x, y});
				area++;
				visited[x][y] = true;
			}
		}

	}
}

int maxAreaOfIsland(vector<vector<int>> grid)
{
	int m = grid.size(), n = grid[0].size();

	vector<vector<bool>>visited(m, vector<bool>(n, false));

	int ans = 0;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!visited[i][j] && grid[i][j] == 1)
			{
				int area = 0;
				dfs(i, j, visited, grid, area); //or bfs
				ans = max(ans, area);
			}
		}
	}

	return ans;
}