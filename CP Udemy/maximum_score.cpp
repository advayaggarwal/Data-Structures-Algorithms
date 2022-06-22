#include<bits/stdc++.h>
using namespace std;

int matrixScore(vector<vector<int>> grid)
{
	int m = grid.size(), n = grid[0].size();
	int ans = (1 << (n - 1)) * m;

	for (int j = 1; j < n; j++)
	{
		int val = 1 << (n - j - 1);
		int set = 0;
		for (int i = 0; i < m; i++)
		{
			if (grid[i][0] == grid[i][j])	set++;
		}

		ans += max(set, m - set) * val;
	}

	return ans;
}