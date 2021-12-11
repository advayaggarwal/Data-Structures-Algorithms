#include<bits/stdc++.h>
using namespace std;

string solve(int n, int m, vector<vector<int>> mat)
{
	int ans = 0;

	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		for (int j = 0; j < m; j++)	sum += mat[i][j];

		ans ^= sum;
	}

	return ans == 0 ? "Second" : "First";
}