#include<bits/stdc++.h>
using namespace std;

void dfs(int i, int j, int m, int n, vector<vector<bool>>&visited, vector<vector<int>>&matrix)
{
	visited[i][j] = true;

	for (int col = 0; col < n; col++)
	{
		int x = i;
		int y = col;

		if (x >= 0 && x < m && y >= 0 && y < n && !visited[x][y] && matrix[x][y])	dfs(x, y, m, n, visited, matrix);
	}

	for (int row = 0; row < m; row++)
	{
		int x = row;
		int y = j;

		if (x >= 0 && x < m && y >= 0 && y < n && !visited[x][y] && matrix[x][y])	dfs(x, y, m, n, visited, matrix);
	}
}

int solve(vector<vector<int>> matrix)
{
	int m = matrix.size();
	int n = matrix[0].size();

	vector<vector<bool>>visited(m, vector<bool>(n, false));
	int ans = 0;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (matrix[i][j] == 1 && !visited[i][j])
			{
				ans++;
				dfs(i, j, m, n, visited, matrix);
			}
		}
	}

	return ans;
}