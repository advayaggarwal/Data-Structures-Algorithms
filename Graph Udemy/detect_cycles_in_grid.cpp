#include<bits/stdc++.h>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool isSafe(int x, int y, int m, int n, int i, int j, vector<vector<char>>& grid)
{
	return x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == grid[i][j];
}

bool dfs(int i, int j, vector<vector<char>>& grid, int m, int n, vector<vector<bool>>&visited, int parentx, int parenty)
{
	visited[i][j] = true;

	for (int k = 0; k < 4; k++)
	{
		int x = i + dx[k];
		int y = j + dy[k];

		if (isSafe(x, y, m, n, i, j, grid) && !visited[x][y])
		{
			if (dfs(x, y, grid, m, n, visited, i, j))  return true;
		}

		else if (isSafe(x, y, m, n, i, j, grid) && visited[x][y] && !(x == parentx && y == parenty))  return true;
	}

	return false;
}

bool containsCycle(vector<vector<char>> grid) {
	int m = grid.size();
	int n = grid[0].size();
	vector<vector<bool>>visited(m, vector<bool>(n, false));

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!visited[i][j])
			{
				if (dfs(i, j, grid, m, n, visited, -1, -1))    return true;
			}
		}
	}
	return false;
}