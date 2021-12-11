#include<bits/stdc++.h>
using namespace std;

#define vvi vector<vector<int>>

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int i, int j, int n, vector<vector<bool>>&visited, vvi &grid, queue<pair<int, int>>&q, vvi &dis)
{
	visited[i][j] = true;
	q.push({i, j});
	dis[i][j] = 0;

	for (int k = 0; k < 4; k++)
	{
		int x = i + dx[k];
		int y = j + dy[k];

		if (x >= 0 && x < n && y >= 0 && y < n && !visited[x][y] && grid[x][y] == 1)
		{
			dfs(x, y, n, visited, grid, q, dis);
		}
	}
}

int shortestBridge(vector<vector<int>> grid)
{
	int n = grid.size();

	vector<vector<bool>>visited(n, vector<bool>(n, false));
	vvi dis(n, vector<int>(n, INT_MAX));
	queue<pair<int, int>>q;

	bool flag = false;

	//Inserting all 1s of first island in the queue using dfs
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (grid[i][j] == 1 && !visited[i][j])
			{
				flag = true;
				dfs(i, j, n, visited, grid, q, dis);
				break;
			}
		}

		if (flag) break;
	}

	//Applying BFS from all the 1s of first island
	while (!q.empty())
	{
		int i = q.front().first;
		int j = q.front().second;

		q.pop();

		for (int k = 0; k < 4; k++)
		{
			int x = i + dx[k];
			int y = j + dy[k];

			if (x >= 0 && x < n && y >= 0 && y < n && !visited[x][y])
			{
				visited[x][y] = true;
				dis[x][y] = dis[i][j] + 1;
				q.push({x, y});

				if (grid[x][y] == 1)	return dis[x][y] - 1;
			}
		}
	}

	return INT_MAX;
}